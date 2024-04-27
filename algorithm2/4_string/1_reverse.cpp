/*************************
 * @file   : 1_reverse.cpp
 * @encode : UTF-8
 * @note   : 反转字符串 https://leetcode.cn/problems/reverse-string/description/
 * @date   : 2024/3/3 10
 *************************/

#include "iostream"
#include "vector"
#include "string"

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
    string s = "hello";
    vector<char> vec(s.begin(), s.end());

    Solution so;
    so.reverseString(vec);
    for (char ch: vec) {
        cout << ch;
    }
    cout << endl;

    return 0;
}
