#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number :";
    cin>>n;

    if((n & (n-1))==0){
        cout<<"numebr is in power of 2";

    }
    else{
        cout<<"number is not in power of 2";
    }
    
}