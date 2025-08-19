#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int width=j-i;
                int height2=min(height[i],height[j]);

                int area=width*height2;
                if(area>maxarea){
                    maxarea=area;
                }
            }
        }
        return maxarea;
    }
};
int main(){
    vector <int>vec={4,5,3,5,7,8};
    Solution s1;
    int ans=s1.maxArea(vec);
    cout<<ans;
}