#include<iostream>
using namespace std;

int main(){
int arr[5]={1,2,3,4,1};

for (int  i = 0; i < 5; i++)
{
    int count = 0;

    //1

    for(int j = 0 ; j < 5 ; j++){
        if(arr[i] == arr[j]){
            count++ ;//1 count = 1 
            
        }
    }

    if(count == 1){
        cout<<arr[i]<<endl;
    }
    
    
}



}