/*************************
 * @file   : 12_str_count.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/10 10
 *************************/

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 1) {
            return 1;
        }
        int ret = 0;
        vector<vector<bool>> dp = vector<vector<bool>>(s.size() + 1, vector<bool>(s.size() + 1, false));

        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                // 0 .. i, i+1, ... j-1, j .. n
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        ret++;
                    } else if (dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                        ret++;
                    }
                }

            }
        }
        return ret;
    }
};

int main() {
    string s = "aaa";

    Solution so;
    cout << so.countSubstrings(s) << endl;
    return 0;
}