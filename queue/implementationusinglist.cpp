#include<iostream>
#include<list>
using namespace std;

class queue{
    list <int> l;
public:
    

    void push(int val){
        l.push_back(val);
        

    }

    void pop(){
        l.pop_front();
    }

    int front(){
        return l.front();
    }

   


};

int main(){
queue q1;

q1.push(15);
q1.push(17);
q1.push(19);
q1.push(20);
q1.push(21);
q1.push(23);

cout<<endl;
cout<<q1.front();

cout<<endl;
q1.pop();

cout<<endl;
cout<<q1.front();




    return 0;
}