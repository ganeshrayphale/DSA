#include<iostream>
using namespace std;
int main(){
    int arr[8] ={4,3,2,1,5,6,8,2};
    int count=8;
    cout<<"before sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i < count; i++)//[4 5 6 7]
    {
        for(int j=i;j<count;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    

}