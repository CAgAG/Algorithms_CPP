/*************************
 * @file   : 26_subset_count.cpp
 * @encode : UTF-8
 * @note   : 编辑距离 https://leetcode.cn/problems/edit-distance/description/
 * @date   : 2024/4/26 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

// word2添加一个元素，相当于word1删除一个元素

class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        // 定义为 dp[i][j] 为在s的前i-1个元素中 和 t[0, j - 1]的最小操作{次数}
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
                    // 替换元素，word1替换word1[i - 1]，使其与word2[j - 1]相同，此时不用增删加元素。
                    // 只需要一次替换的操作，就可以让 word1[i - 1] 和 word2[j - 1] 相同
                    // dp[i - 1][j - 1] + 1: 替换一个字符
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "horse";
    string t = "ros";


    Solution so;
    cout << so.minDistance(s, t) << endl;
    return 0;
}
