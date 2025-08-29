#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int> &nums,int k){
    
   for(int i=1;i<=k;i++) {
       int j=nums.size()-1;
        while(j>0){
        swap(nums[j],nums[j-1]);
        j--;
        }
    }
    
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    rotate(nums,3);
    for(int i : nums){
        cout<<i<< " ";
    }
}