/*************************
 * @file   : 15_robber.cpp
 * @encode : UTF-8
 * @note   : 打家劫舍II https://leetcode.cn/problems/house-robber-ii/description/
 * @date   : 2024/4/24 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/* 分情况考虑3种情况:
 * 1. 选了 第一个房子
 * 2. 选了最后一个房子
 */

class Solution {
public:
    // dp[j] 到j房子之前所能拿到的最大金额
    int rob_(vector<int> &nums, int left, int right) { // 全闭区间
        if (left > right) return 0;
        if (left == right) return nums[left];

        int bag_weight = nums.size() - 1;
        vector<int> dp(bag_weight + 1, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);

        for (int j = left + 2; j <= right; ++j) {
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[j]);
        }
        return dp[right];
    }

    // 针对3种情况
    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        // 1.选了 第一个房子
        int ret_1 = rob_(nums, 0, nums.size() - 2);
        // 2. 选了最后一个房子
        int ret_2 = rob_(nums, 1, nums.size() - 1);
        return max(ret_1, ret_2);
    }
};

int main() {
    vector<int> nums = {2, 3, 2};

    Solution so;
    cout << so.rob(nums) << endl;

    return 0;
}