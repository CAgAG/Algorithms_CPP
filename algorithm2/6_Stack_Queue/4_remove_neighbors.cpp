/*************************
 * @file   : 4_remove_neighbors.cpp
 * @encode : UTF-8
 * @note   : 删除字符串中的所有相邻重复项 https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
 * @date   : 2024/3/7 23
 *************************/

#include "iostream"
#include "stack"
#include "queue"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        if (s.size() < 2) {
            return s;
        }

        stack<char> stack_letter;
        stack_letter.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            char l = s[i];

            if (!stack_letter.empty() && stack_letter.top() == l) {
                stack_letter.pop();
            } else {
                stack_letter.push(l);
            }

        }

        string ret = "";
        while (!stack_letter.empty()) {
            ret += stack_letter.top();
            stack_letter.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution so;

    string input = "abbaca";

    cout << so.removeDuplicates(input) << endl;

    return 0;
}