#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[5] ={4,6,7,8,9};
    int count = 5;
    int target=15;
    int start=0,end=count-1;
    vector <int> vec;
    while (end>start)
    {
        if (arr[start]+arr[end]>target)
        {
            
            end--;
            
        }
        
        else if (arr[start]+arr[end]<target)
        {
           start++;
        }
        else{
            cout<<start<<" "<<end<<endl;
            start++;
            end--;
        }
        
        
        
    }

    
    
    
}