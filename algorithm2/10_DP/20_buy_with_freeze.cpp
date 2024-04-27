/*************************
 * @file   : 20_buy_with_freeze.cpp
 * @encode : UTF-8
 * @note   : 最佳买卖股票时机含冷冻期 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 * @date   : 2024/4/25 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // dp[i][0]: 第i天持有最大金额
        // dp[i][1]: 第i天不持有的最大金额
        // dp[i][2]: 第i天冷静期的最大金额
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < n; ++i) {
            dp[i][2] = dp[i - 1][1];  // 冷静期之前一定是卖出，也即不持有
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);  // 前一天冷静期 才可以 买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);  // 最大值一定是 卖出 或者 冷静期
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 0, 2};

    Solution so;
    cout << so.maxProfit(nums) << endl;


    return 0;
}