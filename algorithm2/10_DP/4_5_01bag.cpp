/*************************
 * @file   : 4_01bag.cpp
 * @encode : UTF-8
 * @note   : 01背包 https://kamacoder.com/problempage.php?pid=1046
 * @date   : 2024/4/22 19
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*
dp[j]: 容量为j的背包的最大价值
递推:
dp[j] = max(dp[j], dp[j - w[i]]+v[i])
 */

int n, bag_weight;// bag_weight代表行李箱空间
void solve() {
    vector<int> weight(n, 0); // 存储每件物品所占空间
    vector<int> value(n, 0);  // 存储每件物品价值
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> value[j];
    }
    vector<int> dp(bag_weight + 1, 0);

    for (int i = 0; i < weight.size(); i++) { // 遍历科研物品
        // 倒序保证每个物品只可以被拿一次
        for (int j = bag_weight; j >= weight[i]; --j) { // 遍历行李箱容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bag_weight] << endl;
}

int main() {
    while (cin >> n >> bag_weight) {
        solve();
    }
    return 0;
}
