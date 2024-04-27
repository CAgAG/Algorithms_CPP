/*************************
 * @file   : 20_buy_with_freeze.cpp
 * @encode : UTF-8
 * @note   : 买卖股票的最佳时机含手续费 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 * @date   : 2024/4/25 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;

        // dp[i][0]: 第i天持有最大金额
        // dp[i][1]: 第i天不持有的最大金额
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);  // 卖出减去手续费
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    Solution so;
    cout << so.maxProfit(nums, fee) << endl;
    return 0;
}