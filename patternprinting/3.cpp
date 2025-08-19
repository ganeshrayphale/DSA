#include<iostream>
using namespace std;
int main(){
    int n=5;
    char letter ='A';
    for(int i=1;i<=n;i++){
        char letter ='A';
        for(int j=1;j<=n;j++){
            cout<<letter++<<" ";
            
        }
        cout<<endl;
    }
}