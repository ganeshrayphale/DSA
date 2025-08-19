#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number :";
    cin>>n;
    int power=1;
    while (power<n)
    {
        power = power<<1;
    }
    if (power==n){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
}