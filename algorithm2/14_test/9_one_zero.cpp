/*************************
 * @file   : 9_one_zero.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/6 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> count_one_zero(string s) {
        int ret_0 = 0;
        int ret_1 = 0;

        for (auto c: s) {
            if (c == '1') {
                ret_1++;
            } else {
                ret_0++;
            }
        }
        return {ret_0, ret_1};
    }

    int findMaxForm(vector<string> &strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < strs.size(); ++i) {
            auto xy = count_one_zero(strs[i]);

            for (int j = m; j >= xy[0]; --j) {
                for (int k = n; k >= xy[1]; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - xy[0]][k - xy[1]] + 1);
                }
            }
        }

        return dp[m][n];
    }
};


int main() {

    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;

    Solution so;
    cout << so.findMaxForm(strs, m, n) << endl;

    return 0;
}
