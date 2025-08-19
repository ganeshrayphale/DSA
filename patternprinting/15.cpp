#include<iostream>
using namespace std;
int main(){
    int n=4;
    for (int  i = 1; i <=n; i++)
    {
        for(int j=n-1;j>= i;j--){
        cout<<"_";
        }

        for(int j=1;j<=1;j++){
        cout<<"*";
        }
        for(int j=1;j<=(2);j++){
            if(i==1){
                break;
            }
            else{
                cout<<"_";
            }
        }
        cout<<endl;
    }
    
}