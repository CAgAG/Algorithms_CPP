/*************************
 * @file   : 20_buy.cpp
 * @encode : UTF-8
 * @note   : 买卖股票的最佳时机 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
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

        // dp[i][0]: 持有某个股票的最大金额 (利润)
        // dp[i][1]: 不持有某个股票的最大金额 (利润)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = -1 * prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; ++i) {
            int cur_price = prices[i];
            // 上一天持有 或者 当天买入
            dp[i][0] = max(dp[i - 1][0], -1 * cur_price);
            // 上一天不持有 或者 当天卖出
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + cur_price);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }

    // ============================
    int maxProfit_1(vector<int> &prices) {
        int ret = 0;
        int left_min = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            int cur_price = prices[i];
            // 贪心: 取最左最小值，取最右最大值
            left_min = min(cur_price, left_min);
            ret = max(cur_price - left_min, ret);
        }
        return ret;
    }

    // ============================
    int maxProfit_2(vector<int> &prices) {
        int ret = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                ret = max(ret, prices[j] - prices[i]);
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    Solution so;
    cout << so.maxProfit(nums) << endl;
    cout << so.maxProfit_1(nums) << endl;
    cout << so.maxProfit_2(nums) << endl;

    return 0;
}
