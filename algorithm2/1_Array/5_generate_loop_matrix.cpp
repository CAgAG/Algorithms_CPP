/*************************
 * @file   : 5_generate_loop_matrix.cpp
 * @encode : UTF-8
 * @note   : 螺旋矩阵II https://leetcode.cn/problems/spiral-matrix-ii/
 * @date   : 2024/2/29 11
 *************************/

// https://www.programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E6%80%9D%E8%B7%AF

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    /* 时间复杂度 O(n^2) */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int start_x = 0, start_y = 0;  // 每一圈的初始位置
        int offset = 1;  // 边界缩减值
        int cur_num = 1;

        int total_loop = n / 2;
        // 只能处理 n为偶数的情况
        int cur_i, cur_j;
        while (total_loop--) {

            // 数据的填充是 左 ==> 右: 左闭右开
            for (cur_j = start_y; cur_j < n - offset; ++cur_j) {
                res[start_x][cur_j] = cur_num;
                cur_num++;
            }

            for (cur_i = start_x; cur_i < n - offset; ++cur_i) {
                res[cur_i][cur_j] = cur_num;
                cur_num++;
            }

            for (; cur_j > start_y; --cur_j) {
                res[cur_i][cur_j] = cur_num;
                cur_num++;
            }

            for (; cur_i > start_x; --cur_i) {
                res[cur_i][start_y] = cur_num;
                cur_num++;
            }

            start_x++;
            start_y++;
            offset++;
        }

        // 填充 n为奇数的情况
        if (n % 2 == 1) {
            res[n / 2][n / 2] = cur_num;
        }

        return res;
    }

};

void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] < 10) {
            cout << " ";
        }

        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {

    Solution so;

    int n = 3;

    vector<vector<int>> out = so.generateMatrix(n);

    for (int i = 0; i < out.size(); ++i) {
        print_vector(out[i]);
    }
    return 0;
}