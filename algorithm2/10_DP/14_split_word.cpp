/*************************
 * @file   : 14_split_word.cpp
 * @encode : UTF-8
 * @note   : 单词拆分
 * @date   : 2024/4/23 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_set"

using namespace std;

/*
而本题其实我们求的是排列数，为什么呢。 拿 s = "applepenapple", wordDict = ["apple", "pen"] 举例。
"apple", "pen" 是物品，那么我们要求 物品的组合一定是 "apple" + "pen" + "apple" 才能组成 "applepenapple"。
"apple" + "apple" + "pen" 或者 "pen" + "apple" + "apple" 是不可以的，那么我们就是强调物品之间顺序。
所以说，本题一定是 先遍历 背包，再遍历物品。
 */

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set <string> wordSet(wordDict.begin(), wordDict.end());  // 去除重复的单词
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int j = 1; j <= s.size(); ++j) {  // 背包
            for (int i = 0; i < j; ++i) {  // 物品
                string word = s.substr(i, j - i);
                if (wordSet.find(word) != wordSet.end() && dp[i]) {  // 找到了
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};

    Solution so;
    cout << so.wordBreak(s, dict) << endl;
    return 0;
}