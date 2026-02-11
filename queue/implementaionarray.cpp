#include<iostream>
using namespace std;

class queue{
int size;
int * p;
int front,rear;

public:
 queue(int size){
    p = new int[size];
    this->front=-1;
    this->rear=-1;

 }

 bool isempty(){
    return (front==-1);
 }

 bool isfull(){
    return (rear==size-1);
 }

 int enqueue(int val){
    if(isfull()){
        cout<<"the queue is full";
        return -1;
    }
    if(isempty()){
        rear++;
        front=0;
        p[rear]=val;


    }

    rear++;
    p[rear]=val;

    return val;
    
 }

 int dequeue(){
    int item;
    if(isempty()){
        cout<<"queue is empty";
        return -1;
    }
   item=p[front];
    front++;
    return item;
 }






}q;


