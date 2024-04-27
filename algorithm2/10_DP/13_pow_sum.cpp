/*************************
 * @file   : 13_pow_sum.cpp
 * @encode : UTF-8
 * @note   : 完全平方数 https://leetcode.cn/problems/perfect-squares/description/
 * @date   : 2024/4/23 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int bag_weight = n;
        vector<int> dp(bag_weight + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i * i <= n; ++i) {
            for (int j = i * i; j <= bag_weight; ++j) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[bag_weight];
    }
};

int main() {
    int n = 11;

    Solution so;
    cout << so.numSquares(n) << endl;

    return 0;
}