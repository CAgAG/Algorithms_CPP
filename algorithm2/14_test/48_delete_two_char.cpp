/*************************
 * @file   : 48_delete_two_char.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/20 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j]: 0..i-1, 0..j-1
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }

            }
        }
        return dp[m][n];
    }
};

int main() {

    string s = "sea";
    string t = "eat";

    Solution so;
    cout << so.minDistance(s, t) << endl;

    return 0;
}