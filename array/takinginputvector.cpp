#include<iostream>
using namespace std;
#include<vector>

int main(){
    int n;
    cout<<"enter the size : ";
    cin>>n;
        vector <int >vec(n);

    for(int i=0;i<n;i++){
       cin>>vec[i];
    }

    for(auto val : vec){
        cout<<val;
    }

}