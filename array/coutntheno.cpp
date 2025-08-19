#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int number = nums[i];
            int count = 1;
            for(int j = 0; j < n; j++) {
                if(number == nums[j] && i != j) {
                    count++;
                }
            }
            if(count > (n / 2)) {
                answer = nums[i];
            }
        }
        return answer;
    }
};

int main() {
    // Test case
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority Element is: " << result << endl;
    return 0;
}
