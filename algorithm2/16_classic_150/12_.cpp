/*************************
 * @file   : 12_.cpp
 * @encode : UTF-8
 * @note   : 整数转罗马数字 https://leetcode.cn/problems/integer-to-roman/submissions/545828984/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/11 17
 *************************/

#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

class Solution {
public:
    map<string, char> trans = {
            {"01", 'I'},
            {"05", 'V'},
            {"11", 'X'},
            {"15", 'L'},
            {"21", 'C'},
            {"25", 'D'},
            {"31", 'M'}
    };

    // 生成10的n次方
    int gen_num(int n) {
        int ret = 1;
        for (int i = 0; i < n; ++i) {
            ret *= 10;
        }
        return ret;
    }

    // 合并两个char为string
    string merge_chars(char c1, char c2) {
        string ret;
        ret.push_back(c1);
        ret.push_back(c2);
        return ret;
    }

    string intToRoman(int num) {
        int n = 0;
        int num_copy = num;
        while (num_copy / 10 != 0) {
            num_copy /= 10;
            n++;
        }

        string s = "";
        for (int n_i = n; n_i >= 0; --n_i) {
            int cur_s_num = num / (gen_num(n_i));
            cur_s_num %= 10;

            if (cur_s_num == 4) {
                if (n_i == 0) {
                    s += "IV";
                } else if (n_i == 1) {
                    s += "XL";
                } else if (n_i == 2) {
                    s += "CD";
                }

            } else if (cur_s_num == 9) {
                if (n_i == 0) {
                    s += "IX";
                } else if (n_i == 1) {
                    s += "XC";
                } else if (n_i == 2) {
                    s += "CM";
                }
            } else {
                while (cur_s_num >= 5) {
                    s += trans[merge_chars('0' + n_i, '5')];
                    cur_s_num -= 5;
                }

                for (int j = 0; j < cur_s_num; ++j) {
                    s += trans[merge_chars('0' + n_i, '1')];
                }
            }

        }


        return s;
    }
};

int main() {
    int num = 58;

    Solution so;
    cout << so.intToRoman(num) << endl;
    return 0;
}