/*************************
 * @file   : 13_.cpp
 * @encode : UTF-8
 * @note   : 最后一个单词的长度 https://leetcode.cn/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/11 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int last_char_index = n - 1;
        for (; last_char_index >= 0; --last_char_index) {
            if (s[last_char_index] != ' ') {
                break;
            }
        }
        // 去除末尾的空格
        s.resize(last_char_index + 1);
        int cur_length = s.size();
        last_char_index = cur_length - 1;
        while (last_char_index >=  0) {
            if (s[last_char_index] == ' ') {
                break;
            }
            last_char_index--;
        }

        return cur_length - last_char_index - 1;
    }
};

int main() {
    string s = "   fly me   to   the moon  ";

    Solution so;
    cout << so.lengthOfLastWord(s) << endl;

    return 0;
}