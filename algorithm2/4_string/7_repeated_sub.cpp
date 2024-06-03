/*************************
 * @file   : 7_repeated_sub.cpp
 * @encode : UTF-8
 * @note   : 重复的子字符串 https://leetcode.cn/problems/repeated-substring-pattern/description/
 * @date   : 2024/3/4 10
 *************************/

#include "iostream"
#include "string"

using namespace std;


class Solution {
public:
    // next(前缀表) 右移一位
    void getNext(int *next, const string &s) {
        // s = "aabaaf"  --> 0 1 0 1 2 0
        // j指向前缀末尾位置，i指向后缀末尾位置; j 同时还代表了上一个字符的最长相等的前后缀
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
                j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
            }
            if (s[i] == s[j]) {  // 找到相同的前后缀
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int next[s.size()];
        getNext(next, s);

        int len = s.size();
        if (next[len - 1] != 0 &&  // 能不能找到对应的前缀
            len % (len - next[len - 1]) == 0) {  // 数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
            // abcabc【abcabc】  ==> 一个周期
            return true;
        }
        return false;
    }
};

int main() {
    string s = "abab";

    Solution so;
    cout << so.repeatedSubstringPattern(s) << endl;

    return 0;
}