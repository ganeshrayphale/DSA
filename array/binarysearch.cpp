#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;
int main(){
    vector<int> vec={8,92,22,92,60,40,62,66,9,15,99};
    sort(vec.begin(), vec.end());

    for(int i : vec){
        cout<<i<<" ";
    }

    int target=8;

    int start=0;
    int end=vec.size()-1;
    
    

    while(start<=end){
        int mid=start+((end-start)/2);
        if(target>vec[mid]){
            start=mid+1;
            
        }
        else if(target<vec[mid]){
            end=mid-1;
            
        }
        else{
            cout<<"the numebr is present at inedex :"<<mid;
            break;
        }
        
    }
    

    

}