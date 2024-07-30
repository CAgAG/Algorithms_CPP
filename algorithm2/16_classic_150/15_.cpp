/*************************
 * @file   : 15_.cpp
 * @encode : UTF-8
 * @note   : Z 字形变换 https://leetcode.cn/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/11 19
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n == 1) {
            return s;
        }

        vector<vector<char>> vec = vector<vector<char>>(numRows, vector<char>(n));
        int cur_s_index = 0;

        int cur_col = 0;
        int cur_row = 0;

        while (cur_s_index < n) {
            // 竖直向下, 上闭下闭
            for (int i = 0; i < numRows; ++i) {
                vec[i][cur_col] = s[cur_s_index];
                cur_s_index++;
                if (cur_s_index >= n) {
                    break;
                }
            }

            cur_col++;
            cur_row = numRows - 2;
            // 135度向上, 左开右开
            int add_num = max(0, numRows - 2);
            for (int i = 0; i < add_num; ++i) {
                vec[cur_row][cur_col] = s[cur_s_index];
                cur_s_index++;
                if (cur_s_index >= n) {
                    break;
                }
                // 更新坐标
                cur_col++;
                cur_row--;
            }
        }

        string ret = "";

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vec[i][j] != '\0') {
                    ret += vec[i][j];
                }
            }
        }
        return ret;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    int k = 4;

    Solution so;
    cout << so.convert(s, k) << endl;

    return 0;
}