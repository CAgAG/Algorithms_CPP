/*************************
 * @file   : 26_subset_count.cpp
 * @encode : UTF-8
 * @note   : 两个字符串的删除操作 https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 * @date   : 2024/4/26 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        // 定义为 dp[i][j] 为在s的前i-1个元素中 和 t[0, j - 1]的最小删除{次数}
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1, 0));  // 使用 uint64_t 防止溢出
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 与 最长公共子序列 判断正好反过来
                if (s[i - 1] == t[j - 1]) {
                    // 保持
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 选一个删，求最小
                    // dp[i - 1][j] + 1: 删除 s一个字符 的操作 {次数 + 1}
                    // dp[i][j - 1] + 1: 删除 t一个字符 的操作 {次数 + 1}
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);  // 还有一个一起删除的 dp[i-1][j-1]+2。但前面已经包括
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "sea";
    string t = "eat";


    Solution so;
    cout << so.minDistance(s, t) << endl;
    return 0;
}
