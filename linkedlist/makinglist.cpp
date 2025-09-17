#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;

    Node(int val){
      data =val;
      next  = NULL;
    }

};

class List{
    Node *head =NULL;
    Node *tail =NULL;

public:
    List(){
        head=tail=NULL;
    }

    void pushfront(int val){   
        Node* newnode=new Node(val);
        if(head==NULL){
            head = tail =newnode;
            return;
        }
        else{
            newnode->next=head;
            head=newnode;
              
        }
    }
    void pushback(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head = tail =newnode;
            return;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    void popback(){
        if(head==NULL){
            cout<<"the list is empty";
        }
        else{
            tail=NULL;
        }
    }

    void showlist(){
        Node *temp = head;
        while(temp!=NULL){
           cout<<"["<<temp->data<<"] ";
           temp=temp->next;


        }
        cout<<endl;
    }


};
int main(){
    List l1;
    l1.showlist();
    l1.pushfront(4);
    l1.showlist();
    l1.pushfront(9);
    l1.showlist();
    l1.pushfront(12);
    l1.showlist();
    l1.pushback(45);
    l1.showlist();
    l1.popback();
    l1.showlist();
    return 0;
}