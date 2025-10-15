#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    int count=1;

    while (fast && fast->next) {
        slow = slow->next;           
        fast = fast->next->next;     
        count++;
        if (slow == fast) {
            
            cout<<count<<" the cycle required to complete"<<endl;
            return true;
        }
    }
    return false; 
}

int main() {
   
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    
    head->next->next->next->next = head->next;

    if (detectLoop(head))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle." << endl;

    return 0;
}
