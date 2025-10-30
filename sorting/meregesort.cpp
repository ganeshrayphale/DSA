#include<iostream>
#include<vector>
using namespace std;
void Merge(int arr[],int start,int end,int mid){
    vector <int> temp;
    int i=start;
    int j=mid+1;
    while(j<=end && i<=mid ){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }

    }
    while(i<=mid){
        temp.push_back(arr[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
            j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+start]=temp[idx];
    }
    return;
}

void mergesort(int arr[],int start,int end){
    
    if(start<end){
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    Merge(arr,start,end,mid);
    }
    
    return;
}
 


int main(){
    int arr[8] ={4,3,2,1,5,6,8,2};
    int count=8;
    cout<<"before sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    
    mergesort(arr, 0, count - 1);



    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    

}