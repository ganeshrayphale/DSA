#include<iostream>
using namespace std;
class node{
public:
        int val;
        node* next;
node(int value){
    val=value;
    next=nullptr;
}



};
class circularlist{
public:
    node* head;
    
    circularlist(){
        head=nullptr;
    }


void pushfront(int val){
node* newnode= new node( val);
if(head==nullptr){
    head=newnode;
    newnode->next=head;
    return;
}
node* temp =head;

while(temp->next!=head) temp=temp->next;

temp->next= newnode;
newnode->next=head;
head = newnode;

}


void pushback(int val){
    node* newnode= new node(val);

    if(head==nullptr){
        head=newnode;
        newnode->next=head;
        return;
    }

    node* temp= head;
    while(temp->next!=nullptr) temp=temp->next;

    temp->next=newnode;
    newnode->next=head;
}
};
int main(){

}