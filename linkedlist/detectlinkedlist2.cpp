/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        bool isCycle= false;
        

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=(fast->next)->next;//[3,2,0,-4]
            if(slow==fast){
                isCycle=true;
                break;
            }
            
        }

        if(isCycle==false){//[1]
             return nullptr;   
        }
        
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;

        }

        return slow;

        
    }
};