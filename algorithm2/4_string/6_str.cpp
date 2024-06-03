/*************************
 * @file   : 6_str.cpp
 * @encode : UTF-8
 * @note   : 实现 strStr() https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 * @date   : 2024/3/3 12
 *************************/

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

/* KMP 算法
 * 核心: 求最长相等的前后缀
 * 前缀: 不包含最后一个字符的子串 后缀: 不包含第一个字符的子串
 * 之前已经匹配过的子串不再重新匹配, 转到与之对应冲突的最长相等的前后缀的后面开始匹配
 */

class Solution {
public:
    // next(前缀表) 右移一位
    void getNext(int *next, const string &s) {
        // s = "aabaaf"  --> 0 1 0 1 2 0
        // j指向前缀末尾位置，i指向后缀末尾位置; j 同时还代表了上一个字符的最长相等的前后缀
        int j = 0;
        next[0] = 0;  // 右移一位
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
                j = next[j - 1]; // 注意这里，是要找【前一位】的对应的回退位置了
            }
            if (s[i] == s[j]) {  // 找到相同的前后缀
                j++;  // 【前一位】
            }
            next[i] = j;  // 与后缀相同字符的坐标是 j
        }
    }

    int strStr(string haystack, string needle) {
        // haystack.size > needle.size
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);

        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    string s = "sadbutsad";
    string t = "sad";

    Solution so;
    cout << so.strStr(s, t);

    return 0;
}