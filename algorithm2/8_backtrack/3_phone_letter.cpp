/*************************
 * @file   : 2_get_K_sum_ele.cpp
 * @encode : UTF-8
 * @note   : 电话号码的字母组合 https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 * @date   : 2024/3/24 22
 *************************/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<char> letters;

    vector<string> ret;
    vector<char> ans;

public:
    void backtrack(int k, int start_index, int end_index) {
        if (ans.size() == k) {
            ret.push_back(string(ans.begin(), ans.end()));
            return;
        }

        if (end_index >= letters.size()) {
            return;
        }

        for (int i = start_index; i <= end_index; ++i) {
            char cur_letter = letters[i];
            if (cur_letter == '!') {
                continue;
            }

            ans.push_back(cur_letter);
            int loop_skip = i / 4;
            backtrack(k, (loop_skip + 1) * 4, (loop_skip + 1) * 4 + 4 - 1);  // 全 闭区间
            ans.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }

        for (char c: digits) {
            if (c == '2') {
                letters.push_back('a');
                letters.push_back('b');
                letters.push_back('c');
                letters.push_back('!');  // 添加一个 ! 用于平衡数量
            } else if (c == '3') {
                letters.push_back('d');
                letters.push_back('e');
                letters.push_back('f');
                letters.push_back('!');
            } else if (c == '4') {
                letters.push_back('g');
                letters.push_back('h');
                letters.push_back('i');
                letters.push_back('!');
            } else if (c == '5') {
                letters.push_back('j');
                letters.push_back('k');
                letters.push_back('l');
                letters.push_back('!');
            } else if (c == '6') {
                letters.push_back('m');
                letters.push_back('n');
                letters.push_back('o');
                letters.push_back('!');
            } else if (c == '7') {
                letters.push_back('p');
                letters.push_back('q');
                letters.push_back('r');
                letters.push_back('s');
            } else if (c == '8') {
                letters.push_back('t');
                letters.push_back('u');
                letters.push_back('v');
                letters.push_back('!');
            } else if (c == '9') {
                letters.push_back('w');
                letters.push_back('x');
                letters.push_back('y');
                letters.push_back('z');
            }
        }
        if (digits.size() == 1) {
            for (char c: letters) {
                if (c == '!') {
                    continue;
                }
                ret.push_back(string(1, c)); // char 转 string
            }
            return ret;
        }

        backtrack(digits.size(), 0, 4);
        return ret;
    }
};

int main() {
    int k = 3, n = 9;

    Solution so;
    auto result = so.letterCombinations("2");
    for (auto vecs: result) {
        cout << vecs << " ";
    }
    cout << endl;
    return 0;
}

