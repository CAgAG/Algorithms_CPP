/*************************
 * @file   : 16_.cpp
 * @encode : UTF-8
 * @note   : 验证回文串 https://leetcode.cn/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/12 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }

        string new_s = "";
        for (char c: s) {
            if (c >= 'a' && c <= 'z') {
                new_s += c;
            } else if (c >= '0' && c <= '9') {
                new_s += c;
            } else if (c >= 'A' && c <= 'Z') {
                new_s += c - 'A' + 'a';
            }
        }

        int left_i = 0, right_i = new_s.size() - 1;
        while (left_i <= right_i) {
            if (new_s[left_i] != new_s[right_i]) {
                return false;
            }
            left_i++;
            right_i--;
        }

        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution so;

    cout << so.isPalindrome(s) << endl;
    return 0;
}
