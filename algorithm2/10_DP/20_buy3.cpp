/*************************
 * @file   : 20_buy.cpp
 * @encode : UTF-8
 * @note   : 买卖股票的最佳时机III https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
 * @date   : 2024/4/25 16
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
        if (n == 0) return 0;

        // dp[i][0]: 不操作
        // dp[i][1]: 第一次持有
        // dp[i][2]: 第一次不持有
        // dp[i][3]: 第二次持有
        // dp[i][4]: 第二次不持有
        /* ==================
         * dp[i][0] = dp[i - 1][0]                                  ==> 不操作
         * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])   ==> 前一天不操作 + 买入
         * dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i])   ==> 前一天持有  + 卖出
         * dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i])   ==> 上一天第一次不持有的基础上 + 买入
         * dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i])   ==> 上一天持有的基础上 + 卖出
         */
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return max(dp[n - 1][2], dp[n - 1][4]);  // 不持有的值肯定更大, 但其实第二次卖出已经包含了第一次卖出的值
    }
};

int main() {
    vector<int> nums = {3, 3, 5, 0, 0, 3, 1, 4};

    Solution so;
    cout << so.maxProfit(nums) << endl;

    return 0;
}
