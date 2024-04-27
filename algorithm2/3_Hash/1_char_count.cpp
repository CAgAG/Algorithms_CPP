/*************************
 * @file   : 1_char_count.cpp
 * @encode : UTF-8
 * @note   : 有效的字母异位词 https://leetcode.cn/problems/valid-anagram/description/
 *           若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * @date   : 2024/3/2 11
 *************************/

#include "iostream"
#include "unordered_map"
#include "string"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;  // 统计字符出现的次数
        for (char ch: s) {
            map[ch]++;
        }
        for (char ch: t) {
            if (map.find(ch) == map.end() || map[ch] <= 0) {
                return false;
            }
            map[ch]--;
        }
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram2(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符 a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和 t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为 0，说明字符串s和t是字母异位词
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";

    Solution so;
    cout << so.isAnagram(s, t) << endl;
    cout << so.isAnagram2(s, t) << endl;
    return 0;
}