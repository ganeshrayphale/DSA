#include<iostream>
using namespace std;
int main(){
    int arr[8] ={4,3,2,1,5,6,8,2};
    int count=8;
    cout<<"before sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i < count-1; i++)//[4 5 6 7]
    {
        for(int j=0;j<count-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    

}