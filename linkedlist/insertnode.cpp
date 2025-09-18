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

    

    void showlist(){
        Node *temp = head;
        while(temp!=NULL){
           cout<<"["<<temp->data<<"]--";
           temp=temp->next;


        }
        cout<<"NULL";

        cout<<endl;
    }

    void popback(){
        if(head==NULL){
            cout<<"the list is empty";
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }   
        else{

            Node* temp=head;
            while (temp->next!=tail)
            {
                temp=temp->next;
            }
            
            temp->next=NULL;
            delete tail;

            tail=temp;
           

            
        }
    }


    void popfront(){
        if (head==NULL){
            cout<<"list is empty";
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        
    }

    void insertnode(int val , int pos){

        if(pos<0){
            cout<<"negative postion not allowed";
            return;
            
        }
         if(pos==0){
            pushfront(val);
            return;
        }

        Node* newnode= new Node(val);

        Node* temp = head;

        for(int j=0;j<pos-1;j++){
            if(temp==NULL){
                return;
            }
            temp=temp->next;

        }
        newnode->next=temp->next;
        temp->next=newnode;
 
    }

    int searchnode(int val){
        Node* temp =head;
        int idx=0;
        while (temp!=NULL)
        {
            if(temp->data==val){
                return idx;
            }
            idx++;
            temp=temp->next;
        }
        return -1;
        
    }

};
int main(){
    List l1;
    l1.pushback(5);
    l1.pushback(6);
    l1.pushback(6);
    l1.pushback(5);
    l1.showlist();
    l1.insertnode(67,2);

    l1.showlist();
    cout<<l1.searchnode(67);
    return 0;
}