/*************************
 * @file   : 12_change.cpp
 * @encode : UTF-8
 * @note   : 零钱兑换 https://leetcode.cn/problems/coin-change/description/
 * @date   : 2024/4/23 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// dp[j]：凑足总额为j所需钱币的最少个数为dp[j]
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int bag_weight = amount;
        vector<int> dp(bag_weight + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= bag_weight; ++j) {
                if (j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[bag_weight] == INT_MAX) {
            return -1;
        }
        return dp[bag_weight];
    }
};

int main() {
    int amount = 11;
    vector<int> coins = {1, 2, 5};

    Solution so;
    cout << so.coinChange(coins, amount) << endl;

    return 0;
}