/*************************
 * @file   : 34_check_subset.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/15 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        // dp[i][j]: 0..i-1, 0..j-1, 匹配的最长子序列
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
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