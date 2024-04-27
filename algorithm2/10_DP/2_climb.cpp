/*************************
 * @file   : 2_climb.cpp
 * @encode : UTF-8
 * @note   : 爬楼梯 https://leetcode.cn/problems/climbing-stairs/description/
 * @date   : 2024/4/22 16
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

// 注意: 求的是 方法数, 不是步数

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n; // 因为下面直接对dp[2]操作了，防止空指针
        // dp[i]： 爬到第i层楼梯，有dp[i]种方法
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    int n = 4;

    Solution so;
    cout << so.climbStairs(n) << endl;

    return 0;
}