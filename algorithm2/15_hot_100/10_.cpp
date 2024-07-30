/*************************
 * @file   : 10_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ret;
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1) {
            return matrix[0];
        }
        if (n == 1) {
            for (int i = 0; i < m; ++i) {
                ret.push_back(matrix[i][0]);
            }
            return ret;
        }

        int offset = 0;
        int src_x = 0;
        int src_y = 0;

        int target_loop = m * n;
        while (target_loop > 1) {
            int start_x = src_x;
            int start_y = src_y;
            // 上 行: 左闭右开
            for (; start_y < n - offset - 1; ++start_y) {
                ret.push_back(matrix[start_x][start_y]);
                target_loop--;
                if (target_loop == 0) {
                    break;
                }
            }

            // 右 列
            for (; start_x < m - offset - 1; ++start_x) {
                ret.push_back(matrix[start_x][start_y]);
                target_loop--;
                if (target_loop == 0) {
                    break;
                }
            }

            // 下 行
            for (; start_y > offset; --start_y) {
                ret.push_back(matrix[start_x][start_y]);
                target_loop--;
                if (target_loop == 0) {
                    break;
                }
            }

            // 左 列
            for (; start_x > offset; --start_x) {
                ret.push_back(matrix[start_x][start_y]);
                target_loop--;
                if (target_loop == 0) {
                    break;
                }
            }

            src_x++;
            src_y++;
            offset++;
        }

        if (target_loop != 0) {
            ret.push_back(matrix[src_x][src_y]);
            target_loop--;
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> nums = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution so;
    for (int a: so.spiralOrder(nums)) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}