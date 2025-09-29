#include<iostream>
using namespace std;
int main(){
    int arr[8] ={4,3,2,1,5,6,8,2};
    int count=8;
    cout<<"before sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<count;i++){
        for (int  j = 1; j < count-2; j++)
        {
           if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j-1]);
           }
        } 
        
    }
    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    

}