/*************************
 * @file   : 9_change.cpp
 * @encode : UTF-8
 * @note   : 零钱兑换II https://leetcode.cn/problems/coin-change-ii/description/
 * @date   : 2024/4/23 19
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    // 装满背包j的dp[j]种方法
    int change(int amount, vector<int> &coins) {
        int bag_weight = amount;
        vector<int> dp(bag_weight + 1, 0);
        dp[0] = 1;
        /* 使用完全背包求 组合、排列数
         * 先物品再背包是 【组合数】
         * 先背包再物品是 排列数
         */
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= bag_weight; ++j) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[bag_weight];
    }

    int change2(int amount, vector<int> &coins) {
        int bag_weight = amount;
        vector<int> dp(bag_weight + 1, 0);
        dp[0] = 1;
        /* 先物品再背包是 组合数
         * 先背包再物品是 【排列数】
         */
        for (int j = 0; j <= bag_weight; ++j) {  // 遍历背包
            for (int i = 0; i < coins.size(); ++i) {  // 【重新】遍历物品
                if (j - coins[i] >= 0) {
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }
        return dp[bag_weight];
    }
};

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    Solution so;
    cout << so.change(amount, coins) << endl;
    cout << so.change2(amount, coins) << endl;

    return 0;
}
