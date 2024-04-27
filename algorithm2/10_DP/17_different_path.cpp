/*************************
 * @file   : 17_different_path.cpp
 * @encode : UTF-8
 * @note   : 不同路径 https://leetcode.cn/problems/unique-paths/description/
 * @date   : 2024/4/25 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        // dp[i][j]: 到当前位置的最大路径数
        // 从左边来 或是 从 上面来
        // dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < n; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 7;

    Solution so;
    cout << so.uniquePaths(m, n) << endl;

    return 0;
}