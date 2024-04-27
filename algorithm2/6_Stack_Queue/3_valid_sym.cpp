/*************************
 * @file   : 3_valid_sym.cpp
 * @encode : UTF-8
 * @note   : 有效的括号 https://leetcode.cn/problems/valid-parentheses/description/
 *           注意第二点: 左括号必须以正确的顺序闭合。
 * @date   : 2024/3/7 23
 *************************/

#include "iostream"
#include "stack"
#include "queue"
#include "string"

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> stack_sym;

        for (char sym: s) {
            if (sym == '(') {
                stack_sym.push(')');
            } else if (sym == '{') {
                stack_sym.push('}');
            } else if (sym == '[') {
                stack_sym.push(']');
            } else {
                if (stack_sym.empty()) {
                    return false;
                }
                // 注意第二点: 左括号必须以正确的顺序闭合。
                char pop_char = stack_sym.top();
                if (pop_char != sym) {
                    return false;
                }
                stack_sym.pop();
            }
        }
        return stack_sym.empty();
    }
};

int main() {
    Solution so;

    string input = "([)]";

    cout << so.isValid(input) << endl;

    return 0;
}