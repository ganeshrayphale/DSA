#include<iostream>
#include<vector>
using namespace std;

class Stack{
public:
    vector <int> vec;

    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(!vec.empty()){
            vec.pop_back();
        }
        else{
            cout<<"empty stack";
        }
    }

    int top() const{
        if(vec.empty()){
            cout << "Stack is empty";
            return;
        }
        return vec[(vec.size())-1];
    }
};
int main(){

    Stack s1;
    s1.push(14);
     s1.push(15);
      s1.push(16);
      s1.top();
      s1.pop();
      s1.top();

      

    return 0;
}