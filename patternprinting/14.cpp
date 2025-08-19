#include<iostream>

using namespace std;
int main(){
    int n=5;
    int num=2;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int j=i-1;j>=1;j--){

            cout<<j;
            num++;
        }

        cout<<endl;
    }
}