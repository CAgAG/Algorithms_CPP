/*************************
 * @file   : 18_split_int.cpp
 * @encode : UTF-8
 * @note   : 整数拆分 https://leetcode.cn/problems/integer-break/description/
 * @date   : 2024/4/25 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {

        // dp[j] 到j的最大乘积和
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = i; j <= n; ++j) {
                // i * (j - i)):  单纯的把整数拆分为两个数相乘
                // dp[j - i] * i: 遍历之前的结果
                // dp[j]: 更新值
                dp[j] = max(dp[j], max(dp[j - i] * i, i * (j - i)));
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 10;

    Solution so;
    cout << so.integerBreak(n) << endl;

    return 0;
}