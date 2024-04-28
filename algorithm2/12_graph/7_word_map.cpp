/*************************
 * @file   : 7_word_map.cpp
 * @encode : UTF-8
 * @note   : 单词接龙 https://leetcode.cn/problems/word-ladder/description/
 * @date   : 2024/4/28 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"
#include "unordered_set"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        unordered_map<string, int> visitedMap;
        queue<string> que;

        visitedMap[beginWord] = 1;
        que.push(beginWord);
        while (!que.empty()) {
            string cur_s = que.front();
            que.pop();
            int cur_dis = visitedMap[cur_s];

            // 构造下一个 可能的字符串，相当于方向
            for (int i = 0; i < cur_s.size(); ++i) {
                string next_s = cur_s;
                // 遍历所有字母来匹配
                for (int j = 0; j < 26; ++j) {
                    next_s[i] = j + 'a';
                    // 不在单词表里
                    if (wordSet.find(next_s) == wordSet.end()) {
                        continue;
                    }
                    // 已经遍历过
                    if (visitedMap.find(next_s) != visitedMap.end()) {
                        continue;
                    }

                    que.push(next_s);
                    visitedMap[next_s] = cur_dis + 1;
                    if (next_s == endWord) {
                        return visitedMap[next_s];
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> word_list = {
            "hot", "dot", "dog", "lot", "log", "cog"
    };

    Solution so;
    cout << so.ladderLength(beginWord, endWord, word_list) << endl;

    return 0;
}