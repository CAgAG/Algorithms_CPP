/*************************
 * @file   : 46_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/27 13
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[i][j]: i..j是否是回文子串
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        int ret = 0;
        string ret_str = "";
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {

                if (s[i] == s[j]) {
                    if (i == j) {
                        dp[i][j] = true;
                        if (1 > ret) {
                            ret = 1;
                            ret_str = s[i];
                        }

                    } else if (j - i == 1) {
                        dp[i][j] = true;
                        if (2 > ret) {
                            ret = 2;
                            ret_str = s.substr(i, 2);
                        }

                    } else if (dp[i + 1][j - 1] == true) {  // 0, ..., i, i+1, ..., j-1, j, ...., end
                        dp[i][j] = true;
                        if (j - i + 1 > ret) {
                            ret = j - i + 1;
                            ret_str = s.substr(i, j - i + 1);
                        }

                    }
                }

            }

        }
        // cout << ret << endl;
        return ret_str;
    }
};

int main() {
    string s = "ccc";
    Solution so;

    cout << so.longestPalindrome(s) << endl;
    return 0;
}