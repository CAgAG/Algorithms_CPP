/*************************
 * @file   : 11_climb_ii.cpp
 * @encode : UTF-8
 * @note   : 爬楼梯（进阶版） https://kamacoder.com/problempage.php?pid=1067
 * @date   : 2024/4/23 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 1阶，2阶，.... m阶就是物品，楼顶n就是背包。
int main() {
    int n, m;
    while (cin >> n >> m) {
        int bag_weight = n;
        vector<int> dp(bag_weight + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= bag_weight; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (j - i >= 0) {
                    dp[j] = dp[j] + dp[j - i];
                }
            }
        }
        cout << dp[bag_weight] << endl;
    }

    return 0;
}