/*************************
 * @file   : 42_climb2.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/17 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    int M, N;  // N 界台阶，最多M步
    while (cin >> N >> M) {
        // dp[i]: 到达i节台阶的方法数
        vector<int> dp = vector<int>(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (i - j >= 0) {
                    dp[i] += dp[i - j];
                } else {
                    break;
                }
            }
        }
        cout << dp[N] << endl;
    }
}