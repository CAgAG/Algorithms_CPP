/*************************
 * @file   : 33_int_split.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/15 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int integerBreak(int n) {

        // dp[i]: 到i之前的最大乘积
        vector<int> dp = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
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