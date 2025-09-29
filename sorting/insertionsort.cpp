#include<iostream>
using namespace std;
int main(){
    int arr[8] ={4,3,2,1,5,6,8,2};//{1,3,2,4,5,6,8,2}
    int count=8;
    cout<<"before sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    for (int i = 1; i < count; i++)//[4 5 6 7]
    {
        int current = i;
        int previous = i-1;
        

        int j=1;

        while(previous>=0 && arr[previous]>arr[current]){
            arr[previous+1]=arr[previous];
            previous--;
            
        }

        arr[previous+1]=arr[current];
        
        
        
        
    }
    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    

}