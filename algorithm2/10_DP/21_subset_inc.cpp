/*************************
 * @file   : 21_subset_inc.cpp
 * @encode : UTF-8
 * @note   : 最长递增子序列 https://leetcode.cn/problems/longest-increasing-subsequence/description/
 * @date   : 2024/4/26 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        // dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
        // 初始化为 1, 包括自己
        vector<int> dp(n, 1);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            // 位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {  // 递增
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};

    Solution so;
    cout << so.lengthOfLIS(nums) << endl;
    return 0;
}