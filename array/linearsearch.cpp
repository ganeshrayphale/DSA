#include<iostream>
using namespace std;

int BianrySearch(int arr[],int size,int number){
    
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]==number)
        {
            return i;
        }
        
        
    }
    return -1;
}
int main(){
    int arr[5]={5,7,3,2,96};
    int idx=BianrySearch(arr,5,96);
    if (idx==(-1)){
        cout<<"number is not presnet in array";
    }
    else{
        cout<<"number is present at index :"<<idx;
    }
    
    
}