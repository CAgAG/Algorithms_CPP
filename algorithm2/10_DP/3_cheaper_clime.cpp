/*************************
 * @file   : 3_cheaper_clime.cpp
 * @encode : UTF-8
 * @note   : 使用最小花费爬楼梯 https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 * @date   : 2024/4/22 19
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

// dp[i]的定义：到达第i台阶所花费的最少体力为dp[i]

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < cost.size() + 1; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};

int main() {
    vector<int> nums = {10, 15, 20};

    Solution so;
    cout << so.minCostClimbingStairs(nums) << endl;

    return 0;
}