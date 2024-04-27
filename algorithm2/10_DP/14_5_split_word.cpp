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


class Solution {
private:
    bool backtrace(string s, unordered_set<string> &wordDict, int start_index, vector<bool>& memory) {
        if (start_index >= s.size()) {
            return true;
        }
        if (memory[start_index]) {
            return false;
        }
        for (int i = start_index; i < s.size(); ++i) {
            string word = s.substr(start_index, i - start_index + 1);
            cout << word << endl;
            if (wordDict.find(word) != wordDict.end()) {
                bool ret = backtrace(s, wordDict, i + 1, memory);
                if (ret) {
                    return true;
                }
            }
        }
        // 寻找失败代码
        memory[start_index] = true;
        cout << start_index << endl;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), false); // -1 表示初始化状态
        return backtrace(s, wordSet, 0, memory);
    }
};

int main() {
    string s = "leetcode";
    vector<string> dict = {"leet", "lee","code"};

    Solution so;
    cout << so.wordBreak(s, dict) << endl;
    return 0;
}