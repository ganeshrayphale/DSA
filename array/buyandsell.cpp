#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy=prices[0];
        int maxprofit=0;
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            bestbuy=min(prices[i],bestbuy);
            if((prices[i]-bestbuy)>maxprofit){
                maxprofit=(prices[i]-bestbuy);
            }
          
        }
        return maxprofit;

    }
};

int main(){
vector <int> vec ={4,1,6,9,5,3};
Solution s1;
int maxi=s1.maxProfit(vec);
cout<<maxi;
}
