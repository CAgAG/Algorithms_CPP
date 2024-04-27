/*************************
 * @file   : 1_reverse.cpp
 * @encode : UTF-8
 * @note   : 反转字符串II https://leetcode.cn/problems/reverse-string-ii/description/
 * @date   : 2024/3/3 10
 *************************/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string ret = s;

        for (int i = 0; i < ret.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k < ret.size()) {
                reverse(ret.begin() + i, ret.begin() + i + k);
            } else {
                reverse(ret.begin() + i, ret.end());
            }
        }
        return ret;
    }
};

int main() {
    string s = "abcdefg";
    cout << s << endl;
    int k = 2;

    Solution so;
    string vc = so.reverseStr(s, k);
    for (char ch: vc) {
        cout << ch;
    }
    cout << endl;

    return 0;
}
