/*************************
 * @file   : 22_subset_repeat.cpp
 * @encode : UTF-8
 * @note   : 最长公共子序列(不一定连续) https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 * @date   : 2024/4/26 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // dp[i][j]: text1 中 前i - 1 与 text2 中 前j - 1 【共同的】最长公共子序列 的长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // dp[i - 1][j]: 表示完整的 text2 和 对应缺一位的 text1 对比
                    // dp[i - 1][j]: 表示完整的 text1 和 对应缺一位的 text2 对比
                    // 例如:
                    // 假设对比到 第3位 ==> ab[c]  text1
                    //                   ac[e]  text2
                    // dp[i - 1][j] 就是考虑 ab  和 ace
                    // dp[i][j - 1] 就是考虑 abc 和 ac
                    // 不减一 就是完整的字符串
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    Solution so;
    cout << so.longestCommonSubsequence(s1, s2) << endl;
    return 0;
}