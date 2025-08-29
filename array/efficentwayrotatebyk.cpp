#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<int> &nums,int k){
    int n=nums.size();
   
    k=k%n;

    // 1 2 3  4 5 6 7
    // 7 6 5 4 3 2 1
    // 4 5 6 7 1 2 3
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),(nums.begin()+k));
    reverse((nums.begin()+k),nums.end());
  
  
 
    
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    rotate(nums,3);
    for(int i : nums){
        cout<<i<< " ";
    }
}