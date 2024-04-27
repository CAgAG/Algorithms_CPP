/*************************
 * @file   : 19_tree_count.cpp
 * @encode : UTF-8
 * @note   : 不同的二叉搜索树 https://leetcode.cn/problems/unique-binary-search-trees/description/
 * @date   : 2024/4/25 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;

        // dp[i]: 到i一共有多少数
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            // j 遍历从 1..i为头节点的个数
            for (int j = 1; j <= i; ++j) {
                // dp[j - 1]: 左子树个数
                // dp[i - j]: 右子树个数
                dp[i] = dp[i] + dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 3;

    Solution so;
    cout << so.numTrees(n) << endl;

    return 0;
}