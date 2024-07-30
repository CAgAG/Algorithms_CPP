/*************************
 * @file   : 45_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/27 13
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ret = 0;
        if (m == 1) {
            for (int i = 0; i < n; ++i) {
                ret += grid[0][i];
            }
            return ret;
        }
        if (n == 1) {
            for (int i = 0; i < m; ++i) {
                ret += grid[i][0];
            }
            return ret;
        }

        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        int left_num;
        int top_num;

        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i - 1 < 0) {
                    top_num = INT_MAX;
                } else {
                    top_num = dp[i - 1][j];
                }
                if (j - 1 < 0) {
                    left_num = INT_MAX;
                } else {
                    left_num = dp[i][j - 1];
                }
                dp[i][j] = min(left_num, top_num) + grid[i][j];

            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {

    vector<vector<int>> nums = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    Solution so;
    cout << so.minPathSum(nums) << endl;

    return 0;
}