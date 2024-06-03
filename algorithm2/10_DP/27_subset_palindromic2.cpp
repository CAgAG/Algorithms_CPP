/*************************
 * @file   : 27_subset_palindromic.cpp
 * @encode : UTF-8
 * @note   : 最长回文子序列(不一定连续) https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 * @date   : 2024/4/26 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

// 回文字符串 是正着读和倒过来读一样的字符串。

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // dp[i][j]: 从i..j区间(全闭区间)的回文串长度
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    // i, [i+1, j-1], j
                    dp[i][j] = dp[i + 1][j - 1] + 2;  // 范围扩大
                }
                if (s[i] != s[j]) {
                    // 删除 i 元素
                    // i, [i+1, j-1, j]
                    // dp[i+1][j]
                    // 删除 j 元素
                    // [i, i+1, j-1], j
                    // dp[i][j-1]
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }

            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    string s = "bbbab";

    Solution so;
    cout << so.longestPalindromeSubseq(s) << endl;
    return 0;
}