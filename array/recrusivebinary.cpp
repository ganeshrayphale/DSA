#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int BinarySearch(vector<int> &nums,int start,int end,int target){
    if(start>end) return -1;
    int mid=(start+end)/2;
    if(target>nums[mid]){
      return  BinarySearch(nums,mid+1,end,target);
    }
    else if(target<nums[mid]){
       return  BinarySearch(nums,start,mid-1,target);
    }
    else{
        return mid;
    }


    
}
int main(){
    vector <int> nums={4,5,6,9,2,19,16};
    sort(nums.begin(),nums.end());
    int target=19;
    int idx = BinarySearch(nums,0,(nums.size()-1),target);

    cout<<idx;

    


}
