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
dp[i][j]: 0..i的物品放入容量为j的背包 的最大价值
 状态(选择)-价值:
 不放物品i: dp[i-1][j]
  放物品i: dp[i-1][j-weight] + value[i]
 递推公式: max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
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
    // dp数组, dp[i][j]代表行李箱空间为j的情况下,从下标为[0, i]的物品里面任意取,能达到的最大价值
    vector<vector<int>> dp(weight.size(), vector<int>(bag_weight + 1, 0));

    // 初始化, 因为需要用到dp[i - 1]的值
    // j < weight[0]已在上方被初始化为0
    // j >= weight[0]的值就初始化为value[0]
    for (int j = weight[0]; j <= bag_weight; j++) {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) { // 遍历科研物品
        for (int j = 0; j <= bag_weight; j++) { // 遍历行李箱容量
            // 如果装不下这个物品,那么就继承dp[i - 1][j]的值
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
                // 如果能装下,就将值更新为 不装这个物品的最大值 和 装这个物品的最大值 中的 最大值
                // 装这个物品的最大值由容量为j - weight[i]的包任意放入序号为[0, i - 1]的最大值 + 该物品的价值构成
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            // dp[i - 1][j - weight[i]] 为背包容量为j - weight[i]的时候不放物品i的最大价值
        }
    }
    cout << dp[weight.size() - 1][bag_weight] << endl;
}

int main() {
    while (cin >> n >> bag_weight) {
        solve();
    }
    return 0;
}

// 这里可以看出公式中的 dp[i-1]是可以重复利用的
// 这就是滚动数组的由来，需要满足的条件是上一层可以重复利用，直接拷贝到当前层。