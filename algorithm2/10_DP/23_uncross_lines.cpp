/*************************
 * @file   : 23_uncross_lines.cpp
 * @encode : UTF-8
 * @note   : 不相交的线 https://leetcode.cn/problems/uncrossed-lines/description/
 * @date   : 2024/4/26 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 与上一题一样

// 不相交 其实就是 子序列顺序不变
class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        // dp[i][j]: text1 中 前i - 1 与 text2 中 前j - 1 【共同的】最长公共子序列 的长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 可能是之前字符的长度
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};


int main() {
    vector<int> nums = {1, 4, 2};
    vector<int> nums2 = {1, 2, 4};

    Solution so;
    cout << so.maxUncrossedLines(nums, nums2) << endl;
    return 0;
}