#include<iostream>
using namespace std;
int main(){
    int arr[6]={4,9,66,2,56,0};
    int largest=arr[0];
    int idx=0;

    for (int  i = 0; i < 6; i++)
    {
        if(arr[i]>largest){
            idx=i;
            largest= arr[i];
            
        }
    }
    cout<<"largest is :"<<largest<<"["<<idx<<"]";
    
}