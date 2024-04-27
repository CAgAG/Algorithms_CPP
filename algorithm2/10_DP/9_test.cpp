/*************************
 * @file   : 9_test.cpp
 * @encode : UTF-8
 * @note   : 测试 01背包和完全背包的区别
 * @date   : 2024/4/23 15
 *************************/

#include "iostream"
#include "vector"

using namespace std;


// 完全背包
void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        // 正序会重复使用到之前的数据
        for (int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
            cout << "=======================" << endl;
            cout << "dp[" << j - weight[i] << "]=" << dp[j - weight[i]] << ", +" << value[i] << ", " << "dp[" << j << "]=" << dp[j] << endl;
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << "dp[" << j << "]=" << dp[j] << endl;
            cout << "=======================" << endl;

        }
    }
    cout << dp[bagWeight] << endl;
}

// 01 背包
void test_CompletePack2() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        // 倒序只会使用数据一次
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            cout << "=======================" << endl;
            cout << "dp[" << j - weight[i] << "]=" << dp[j - weight[i]] << ", +" << value[i] << ", " << "dp[" << j << "]=" << dp[j] << endl;
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << "dp[" << j << "]=" << dp[j] << endl;
            cout << "=======================" << endl;

        }
    }
    cout << dp[bagWeight] << endl;
}

int main() {
    test_CompletePack();
    cout << "########################" << endl;
    test_CompletePack2();
}