/*************************
 * @file   : 4_buy_profit.cpp
 * @encode : UTF-8
 * @note   : 买卖股票的最佳时机 II https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 * @date   : 2024/4/10 12
 *************************/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

// 局部最优：收集每天(与前一天比较得到)的正利润，全局最优：求得最大利润
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> per_profit(prices.size(), 0);
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            per_profit[i] = prices[i] - prices[i - 1];
            if (per_profit[i] > 0) {
                ret += per_profit[i];
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    Solution so;
    cout << so.maxProfit(nums) << endl;

    return 0;
}
