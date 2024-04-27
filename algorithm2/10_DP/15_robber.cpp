/*************************
 * @file   : 15_robber.cpp
 * @encode : UTF-8
 * @note   : 打家劫舍 https://leetcode.cn/problems/house-robber/description/
 * @date   : 2024/4/24 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int bag_weight = nums.size() - 1;
        vector<int> dp(bag_weight + 1, 0);;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // dp[j] 到j房子之前所能拿到的最大金额
        for (int j = 2; j < nums.size(); ++j) {
            dp[j] = max(dp[j - 2] + nums[j], dp[j - 1]);
        }

        return dp[bag_weight];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};

    Solution so;
    cout << so.rob(nums) << endl;

    return 0;
}