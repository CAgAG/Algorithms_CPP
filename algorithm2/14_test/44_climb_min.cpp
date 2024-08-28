/*************************
 * @file   : 44_climb_min.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/17 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    // 其中 【cost[i]】 是从楼梯第 i 个台阶向上爬需要【支付的费用】。一旦你支付此费用，即可选择【向上爬一个或者两个台阶】
    int minCostClimbingStairs(vector<int> &cost) {

        int n = cost.size();
        // dp[i]: 到达i阶台阶的最小花费
        vector<int> dp = vector<int>(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = min(cost[0], cost[1]);

        for (int i = 3; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

int main() {
    vector<int> nums = {10, 15, 20};

    Solution so;
    cout << so.minCostClimbingStairs(nums) << endl;

    return 0;
}