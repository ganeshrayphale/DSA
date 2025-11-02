#include<iostream>
using namespace std;


class Node{
public:
    int val;
    Node* next;
    Node* previous;

Node(int value){
    val=value;
    next=nullptr;
    previous=nullptr;

    }

};

class doublylist{
     Node* head;
public:
doublylist(){
    head=nullptr;
}

void pushback(int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        head=newnode;
        return;

    }
    Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

    temp->next=newnode;
    newnode->previous=temp;

}

void pushfornt(int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    
    head->previous=newnode;
    newnode->next=head;

    head=newnode;
    return;
}

void popback(){
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp =head;
    while (temp->next!=nullptr )
    {
        temp=temp->next;
    }
    temp->previous->next=nullptr;
    delete temp;
    
    
}
void popfornt(){
    if(head==nullptr){
        cout<<"the list is empty";
        return;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    Node* temp=head;
    head=head->next;
    head->previous=nullptr;
    temp->next=nullptr;
    delete temp;
    


}

void ShowList(){
    Node* temp =head;
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
        
    }
    cout<<"null"<<endl;
    return;
}

};


int main(){

    doublylist l1;
    l1.pushback(45);
    l1.pushback(63);
    l1.ShowList();
    l1.pushfornt(5);
    l1.ShowList();
    l1.popback();
    l1.ShowList();
    l1.popfornt();
    l1.ShowList();
    return 0;

}



    
