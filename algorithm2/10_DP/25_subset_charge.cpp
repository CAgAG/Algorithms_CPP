/*************************
 * @file   : 25_subset_charge.cpp
 * @encode : UTF-8
 * @note   : 判断子序列 https://leetcode.cn/problems/is-subsequence/description/
 * @date   : 2024/4/26 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = t.size(), n = s.size();

        // dp[i][j]: t 中 i- 1 和 s 中 j- 1 的相同子序列的【能够匹配的子序列个数】个数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n] == s.size();
    }
};

int main() {
    string s = "abc";
    string t = "ahbgdc";


    Solution so;
    cout << so.isSubsequence(s, t) << endl;
    return 0;
}