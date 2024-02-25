/*************************
 * @file   : example.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/16 12
 *************************/

/* 给出一个数字三角形，从顶点出发每次向 下 或 右下 走一步直至最底层，将途径的数字相加，问得到最大值。*/

#include "vector"
#include "iostream"

using namespace std;

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    vector<vector<int>> data = {
            {7},
            {3, 8},
            {8, 1, 0},
            {2, 7, 4, 4},
            {4, 5, 2, 6, 5}
    };  // 7 -> 3 -> 8 -> 7 -> 5 = 30

    // 定义状态 f(i, j)表示从(1, 1)出发走到(i, j)所有路径的最大和。
    // 考虑哪些状态对 f这个状态有影响。
    //      上一步向下: (i-1, j)   -> (i, j)
    //      上一步右下: (i-1, j-1) -> (i, j)
    // 如何转移?
    //      f(i, j) = max( f(i-1, j), f(i-1, j-1) ) + data(i, j)
    /* 相当于每步都在贪心选择局部最优 */

    vector<vector<int>> f(data.size() + 1, vector<int>(data.size() + 1, 0));
    int ans = 0;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            int f_i = i + 1, f_j = j + 1;  // 防止越界
            f[f_i][f_j] = max(f[f_i - 1][f_j - 1], f[f_i - 1][f_j]) + data[i][j];
            if (f[f_i][f_j] > ans) {
                ans = f[f_i][f_j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}