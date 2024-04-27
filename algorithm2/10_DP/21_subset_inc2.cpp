/*************************
 * @file   : 21_subset_inc.cpp
 * @encode : UTF-8
 * @note   : 最长连续递增序列 https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 * @date   : 2024/4/26 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 1;

        // dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
        // 初始化为 1, 包括自己
        vector<int> dp(n, 1);

        int ret = 0;
        for (int i = 1; i < n; ++i) {
            // 保证连续 和 递增
            if (nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);  // 保证连续: 直接拿上一个就行了
            }

            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7};

    Solution so;
    cout << so.findLengthOfLCIS(nums) << endl;
    return 0;
}