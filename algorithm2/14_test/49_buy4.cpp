/*************************
 * @file   : 49_buy4.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/20 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {

        int n = prices.size();
        int total_k = 2 * k;
        // dp[i][0]: 未操作
        // dp[i][1]: 第一次持有
        // dp[i][2]: 第一次不持有
        // 。。。
        // dp[i][2*k-1]: 第k次持有
        // dp[i][2*k]: 第k次不持有
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(total_k + 1, 0));

        for (int i = 0; i <= total_k; ++i) {
            if (i % 2 == 1 && i != 0) {
                dp[0][i] = -prices[0];
            }
        }

        for (int i = 1; i < n; ++i) {
            int cur_p = prices[i];

            for (int j = 0; j <= total_k; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (j % 2 == 1) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - cur_p);
                } else if (j % 2 == 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + cur_p);
                }
            }
        }

        return dp[n - 1][total_k];
    }
};

int main() {

    int k = 2;
    vector<int> nums = {3, 3, 5, 0, 0, 3, 1, 4};

    Solution so;
    cout << so.maxProfit(k, nums) << endl;

    return 0;
}