#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(&arr[i], &arr[size - i - 1]);
    }
}

int main(){
    int arr[8]={9,9,6,2,3,6,4,5};
    int size=8;
    for (int i = 0; i < size; i++)
    {
        cout<<"["<<arr[i]<<"] ";
    }
    cout<<endl;
    reverse(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<"["<<arr[i]<<"] ";
    }
}