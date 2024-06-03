/*************************
 * @file   : 26_subset_count.cpp
 * @encode : UTF-8
 * @note   : 不同的子序列 https://leetcode.cn/problems/distinct-subsequences/description/
 * @date   : 2024/4/26 17
 *************************/
// 与上题的区别在于：这题要求的是整个子序列出现的次数，而上题要求的是子序列本身的字符数

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        /* 定义为 dp[i][j] 为在s的前i个元素(即s[0, i - 1])中，有多少个t[0, j - 1]的匹配(以t[j - 1]为结尾)
         * 假设 t="bag" 两种转移情况分别为:
         *  当此元素相等时, 则求s的前面有多少个"ba" + 前面有多少个完整"bag"
         *  若此元素不相等, 则求s的前面有多少个"bag"
         */
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1, 0));  // 使用 uint64_t 防止溢出
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    // dp[i - 1][j - 1]: 考虑 i-1这个元素
                    // dp[i - 1][j]: 不考虑 i-1这个元素，相当于删掉它 (或者是直接固定对应子串，考虑子串的下一位)
                    // 例如: i-1,j-1到达使用[]表示
                    // bag[g]  ==> s  是否考虑删掉 g
                    //  ba[g]  ==> t
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // 保持 t 也就是例子中的bag
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "rabbbit";
    string t = "rabbit";


    Solution so;
    cout << so.numDistinct(s, t) << endl;
    return 0;
}
