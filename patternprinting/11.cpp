#include<iostream>

using namespace std;
int main(){
    int n=10;
    int num=1;
    for(int i=1;i<=n;i++){

        for(int j=i;j>=1;j--){
            cout<<num++<<" " ;
        }
        
        cout<<endl;
    }
}