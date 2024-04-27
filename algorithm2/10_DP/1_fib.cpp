/*************************
 * @file   : 1_fib.cpp
 * @encode : UTF-8
 * @note   : 斐波那契数 https://leetcode.cn/problems/fibonacci-number/description/
 * @date   : 2024/4/22 15
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

// 1. 确定dp数组以及下标的含义
//    dp[i]的定义为：第i个数的斐波那契数值是dp[i]
// 2. 确定递推公式
//    dp[i] = dp[i - 1] + dp[i - 2]
// 3. dp数组如何初始化
// 4. 确定遍历顺序
// 5. 举例推导dp数组


class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fib2(int n) {
        if (n <= 1) {
            return n;
        }

        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            int sum = dp[0] + dp[1];

            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main() {
    int  n = 5;

    Solution so;
    cout << so.fib(n) << endl;
    cout << so.fib2(n) << endl;

    return 0;
}