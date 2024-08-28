/*************************
 * @file   : 10_tree_count.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/10 09
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int numTrees(int n) {

        if (n == 1 ) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        vector<int> dp = vector<int>(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = dp[i] + dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {

    int  n = 3;

    Solution so;
    cout << so.numTrees(n) << endl;

    return 0;
}