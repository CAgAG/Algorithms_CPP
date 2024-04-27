/*************************
 * @file   : 2_reverse_str.cpp
 * @encode : UTF-8
 * @note   : 反转字符串 https://leetcode.cn/problems/reverse-string/description/
 * @date   : 2024/3/5 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        // i 从左向右; j 从右向左
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
            char tp = s[i];
            s[i] = s[j];
            s[j] = tp;
        }
    }
};

int main() {
    vector<char> s = {'h','e','l','l','o'};

    Solution so;
    so.reverseString(s);
    for (char t: s) {
        cout << t;
    }
    cout << endl;
    return 0;
}