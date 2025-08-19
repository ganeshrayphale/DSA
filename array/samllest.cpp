#include<iostream>
using namespace std;
int main(){
    int arr[6]={4,9,6,2,56,0};
    int smallest=arr[0];

    for (int  i = 0; i < 6; i++)
    {
        if(arr[i]<smallest){
            smallest= arr[i];
        }
    }
    cout<<"smallest is :"<<smallest;
    
}