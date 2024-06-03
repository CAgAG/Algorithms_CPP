/*************************
 * @file   : 8_one_and_zero.cpp
 * @encode : UTF-8
 * @note   : 一和零(两个维度的01背包) https://leetcode.cn/problems/ones-and-zeroes/description/
 * @date   : 2024/4/23 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    vector<int> count_01(string s) {
        int count_0 = 0;
        int count_1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                count_1++;
            } else {
                count_0++;
            }
        }
        return {count_0, count_1};
    }

    // dp[i][j]: 装满 i个0，j个1最多装多少物品
    /* 假设 当前遍历元素 有 x个0，y个1
     * 结合 01背包的公式对比: dp[i] = max(dp[j], dp[j - W[i]] + V[i])
     * ==> 装入的【元素个数】就是【价值】，背包容量就是m和n
     * 那么递推公式就是: dp[i][j] = max(dp[i][j], dp[i-x][j-y]+1)
     */
    int findMaxForm(vector<string> &strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 遍历物品
        for (int k = 0; k < strs.size(); ++k) {
            string cur_s = strs[k];
            vector<int> xy = count_01(cur_s);
            int x = xy[0];
            int y = xy[1];

            // 遍历背包
            for (int i = m; i >= x; --i) {
                for (int j = n; j >= y; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);  // 此时的价值就是物品的数量
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<string> nums = {"10", "0001", "111001", "1", "0"};

    Solution so;
    cout << so.findMaxForm(nums, 5, 3);

    return 0;
}