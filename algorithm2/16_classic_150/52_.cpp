/*************************
 * @file   : 52_.cpp
 * @encode : UTF-8
 * @note   : 串联所有单词的子串 https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/25 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        if (s.size() == 0 || words.size() == 0) {
            return {};
        }

        vector<int> ret;

        int words_single_len = words[0].size();  // words中每个单词的长度
        int words_len = words.size();

        // word出现的次数
        unordered_map<string, int> w_c;
        for (auto w: words) {
            w_c[w]++;
        }

        // words_single_len， 全匹配, 可能不是第一个字符开始匹配 words
        for (int i = 0; i < words_single_len; ++i) {
            //left和 right表示窗口的左右边界，count用来统计匹配的单词个数
            int left = i, right = i, count = 0;

            // s子串出现的次数
            unordered_map<string, int> s_c;

            // 滑动窗口
            // s = ab, ...【left, ..., right】, ..., xyz
            while (right + words_single_len <= s.size()) {
                // 从s中提取一个单词拷贝到w
                string w = s.substr(right, words_single_len);
                // 窗口右边界右移一个单词的长度
                right += words_single_len;

                // 此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及 s_c
                if (w_c.count(w) == 0) {
                    count = 0;
                    left = right;
                    s_c.clear();
                } else {  // 单词匹配成功, 在words中
                    s_c[w]++;
                    count++;

                    // 一个单词匹配次数超了，需要缩小窗口，也就是left右移
                    // 保证区间内的字符 是符合 words的
                    while (s_c[w] > w_c[w]) {
                        string t_w = s.substr(left, words_single_len);
                        count--;
                        s_c[t_w]--;
                        left += words_single_len;
                    }
                    // 全部匹配
                    if (count == words_len) {
                        ret.push_back(left);
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution so;
    for (auto c: so.findSubstring(s, words)) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}