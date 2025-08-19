#include<iostream>
using namespace std;
int main(){
    int n=5;
    char len='A';
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){
            cout<<len++<<" ";
        }
        cout<<endl;
    }
}