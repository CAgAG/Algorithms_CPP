/*************************
 * @file   : 27_subset_palindromic.cpp
 * @encode : UTF-8
 * @note   : 回文子串 https://leetcode.cn/problems/palindromic-substrings/description/
 * @date   : 2024/4/26 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

// 回文字符串 是正着读和倒过来读一样的字符串。
// 子字符串 是字符串中的由[连续]字符组成的一个序列。

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 1) {
            return 1;
        }

        // dp[i][j]: i..j这个区间是 回文子串, 左闭右闭区间
        vector<vector<bool>> dp = vector(n + 1, vector<bool>(n + 1, false));

        int ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {  // i和j对应区间边界的元素相同
                    if (j - i <= 1) { // 区间有1个或者2个元素
                        dp[i][j] = true;
                        ret++;
                    } else if (dp[i + 1][j - 1] == true) { // i和j区间的里面是回文子串的情况, 注意此处是 i+1
                        // i, [i+1, j-1], j
                        dp[i][j] = true;
                        ret++;
                    }
                }

            }
        }
        return ret;
    }

    // 双指针法
    // 在遍历中心点的时候，要注意中心点有两种情况。
    // 一个元素可以作为中心点，两个元素也可以作为中心点。
    // 三个元素还可以做中心点呢。其实三个元素就可以由一个元素左右添加元素得到，四个元素则可以由两个元素左右添加元素得到。
    int countSubstrings2(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }

    // 以中心向外扩散，看是否是相同的连续字符
    int extend(const string &s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};

int main() {
    string s = "aaa";

    Solution so;
    cout << so.countSubstrings(s) << endl;
    cout << so.countSubstrings2(s) << endl;
    return 0;
}