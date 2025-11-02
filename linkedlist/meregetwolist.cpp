#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        if (list1->val < list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;

        return head;
    }
    
    void printList(ListNode* head) {
        while (head) {
            std::cout << head->val;
            if (head->next) std::cout << " -> ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> vals1 = {1, 3, 5};
    std::vector<int> vals2 = {2, 4, 6};

    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList(vals2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    std::cout << "Merged list: ";
    sol.printList(merged);

    while (merged) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}
