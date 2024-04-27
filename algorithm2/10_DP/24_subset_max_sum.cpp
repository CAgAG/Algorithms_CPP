/*************************
 * @file   : 24_subset_max_sum.cpp
 * @encode : UTF-8
 * @note   : 最大子序和 https://leetcode.cn/problems/maximum-subarray/description/
 * @date   : 2024/4/26 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // dp[i]: 到 i之前的最大连续子序列和
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];

        int ret = dp[0];
        for (int i = 1; i < n; ++i) {
            // 上一个累加 或是 重新开始
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {-1, -2};


    Solution so;
    cout << so.maxSubArray(nums) << endl;
    return 0;
}