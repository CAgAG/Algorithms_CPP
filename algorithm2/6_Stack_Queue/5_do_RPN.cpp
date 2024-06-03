/*************************
 * @file   : 5_do_RPN.cpp
 * @encode : UTF-8
 * @note   : 逆波兰表达式求值 https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
 * @date   : 2024/3/8 09
 *************************/

#include "iostream"
#include "stack"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<long long> stack_sym;
        // 栈每次遇到 运算符 就 弹出两个数
        // 运算结果 还要 再压入栈
        long long num1, num2;

        for (string sym: tokens) {
            if (sym == "+") {
                num2 = stack_sym.top();
                stack_sym.pop();
                num1 = stack_sym.top();
                stack_sym.pop();
                stack_sym.push(num1 + num2);
            } else if (sym == "-") {
                num2 = stack_sym.top();
                stack_sym.pop();
                num1 = stack_sym.top();
                stack_sym.pop();
                stack_sym.push(num1 - num2);
            } else if (sym == "*") {
                num2 = stack_sym.top();
                stack_sym.pop();
                num1 = stack_sym.top();
                stack_sym.pop();
                stack_sym.push(num1 * num2);
            } else if (sym == "/") {
                num2 = stack_sym.top();
                stack_sym.pop();
                num1 = stack_sym.top();
                stack_sym.pop();
                stack_sym.push(num1 / num2);
            } else {
                stack_sym.push(stoll(sym));
            }
        }
        return stack_sym.top();
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    Solution so;

    cout << so.evalRPN(tokens) << endl;

    return 0;
}