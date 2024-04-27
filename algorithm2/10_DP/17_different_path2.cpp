/*************************
 * @file   : 17_different_path.cpp
 * @encode : UTF-8
 * @note   : 不同路径II https://leetcode.cn/problems/unique-paths-ii/description/
 * @date   : 2024/4/25 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // dp[i][j] 表示 到达 i，j位置的最大路径数
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                // 障碍无法到达
                break;
            } else {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                // 障碍无法到达
                break;
            } else {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    // 障碍无法到达
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> map{
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    Solution so;
    cout << so.uniquePathsWithObstacles(map) << endl;

    return 0;
}