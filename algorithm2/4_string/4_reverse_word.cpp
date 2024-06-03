/*************************
 * @file   : 4_reverse_word.cpp
 * @encode : UTF-8
 * @note   : 翻转字符串里的单词 https://leetcode.cn/problems/reverse-words-in-a-string/description/
 * @date   : 2024/3/3 11
 *************************/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string replace_space(string s) {
        // 去除右多余的空格
        int space_right = s.size() - 1;
        while (s[space_right] == ' ') space_right--;
        int new_size = space_right + 1;

        // 统计左多余的空格
        int space_left = 0;
        while (s[space_left] == ' ') space_left++;
        // 移动字符，有效字符向左移
        int new_i = 0;
        for (int i = space_left; i < new_size; ++i) {
            s[new_i] = s[i];
            new_i++;
        }
        new_size = new_size - space_left;
        // 去除左右空格
        s.resize(new_size);
        // =====================================

        // 移除中间的空格
        int space_mid = 0;
        int right_point = new_size - 1;
        while (right_point > 0) {
            if (s[right_point] == ' ' && s[right_point - 1] == ' ') {
                space_mid += 1;
                // 左移一位，right_point 到 结尾
                for (int i = right_point; i < new_size - 1; ++i) {
                    s[i] = s[i + 1];
                }
                right_point = right_point;
            } else {
                right_point--;
            }
        }
        s.resize(new_size - space_mid);
        return s;
    }

    string reverseWords(string s) {
        s = replace_space(s);

        // 反转整个字符串
        reverse(s.begin(), s.end());

        // 对单个单词反转
        int left_i = 0;
        for (int right_i = 0; right_i <= s.size(); ++right_i) {
            if (s[right_i] == ' ' || right_i == s.size()) {
                reverse(s.begin() + left_i, s.begin() + right_i);
                left_i = right_i + 1;
            }
        }
        return s;
    }
};

int main() {
    string s = "  the   sky     is  blue    ";
    cout << s << endl;

    Solution so;
    string vc = so.reverseWords(s);
    for (char ch: vc) {
        cout << ch;
    }
    cout << endl;

    return 0;
}