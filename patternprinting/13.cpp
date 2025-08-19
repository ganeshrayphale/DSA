#include<iostream>

using namespace std;
int main(){
    int n=5;
    int num=1;
    for(int i=1;i<=n;i++){
        
        for(int k=1;k<=i;k++){
            cout<<"  " ;
        }
        for(int j=n;j>=i;j--){
            cout<<i<<" " ;
        }
       
        
        cout<<endl;
    }
}