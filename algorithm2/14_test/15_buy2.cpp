/*************************
 * @file   : 15_buy2.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/11 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int n = prices.size();

        // dp[i][0]: 持有股票
        // dp[i][1]: 不持有股票
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; ++i) {
            int cur_p = prices[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - cur_p);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + cur_p);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    vector<int> p = {7, 1, 5, 3, 6, 4};

    Solution so;
    cout << so.maxProfit(p) << endl;

    return 0;
}