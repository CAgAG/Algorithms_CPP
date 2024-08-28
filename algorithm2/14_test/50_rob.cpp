/*************************
 * @file   : 50_rob.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/20 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        // dp[i]: 到第i家的最大金额
        vector<int> dp = vector<int>(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 1};

    Solution so;
    cout << so.rob(nums) << endl;

    return 0;
}