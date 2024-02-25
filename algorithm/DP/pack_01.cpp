/*************************
 * @file   : pack_01.cpp
 * @encode : UTF-8
 * @note   : 01背包问题
 * @date   : 2024/2/16 15
 *************************/

/* 有 N 件物品和一个容量为 W 的背包。放入第 i 件物品的体积是 w_i，得到的价值是 v_i。求解将哪些物品装入背包可使价值总和最大 */

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/* f[i][j]表示只看前i个物品，总体积是j的情况下，总价值最大是多少。
 *     注意: 索引i和j都有对应的表示含义  ==> j是总容量
 * result=max{f[n][0~V]}
 * 状态：
 * f[i][j]有两种情况：
 *     p1.不选第i个物品，f[i][j]=f[i-1][j]；那么直接用前 i-1物品且同体积的价值即可，不选的话体积是不变的
 *     p2.选第i个物品，f[i][j]=f[i-1][j-v[i]] + w[i]；那么价值是 前i-1物品中剩余 j-v[i]体积的价值 + 当前物品的价值
 * 状态转移:
 *     f[i][j] = max(p1., p2.)
 * 初始状态:
 *     f[0][0] = 0;
 */

int main() {
    const int N=5, W = 10;
    vector<int> ob_w = {1, 2, 3, 4, 5};  // 物品重量
    vector<int> ob_v = {2, 3, 1, 2, 2};  // 物品价值
    int f[N + 1][W + 1]={};
    f[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j >= ob_w[i]) {  // 总容量 j可以装入第 i个物品
                f[i][j] = max(f[i - 1][j],  // 不选
                              f[i - 1][j - ob_w[i]] + ob_v[i]);  // 选择
            }
        }
    }

    int ans=0;
    for (int j = 0; j <= W; ++j) {
        if (f[N][j] > ans) {
            ans = f[N][j];
        }
    }
    cout << ans << endl;
    return 0;
}
