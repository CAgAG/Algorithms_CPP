/*************************
 * @file   : 11_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // 按列翻转
        for (int i = 0; i < n; ++i) {
            int top = 0;
            int bottom = m - 1;
            while (top < bottom) {
                int tp = matrix[top][i];
                matrix[top][i] = matrix[bottom][i];
                matrix[bottom][i] = tp;

                top++;
                bottom--;
            }
        }

        // 主对角线翻转
        for (int i = 0; i < n; ++i) {

            int right_x = i - 1;
            int right_y = i;

            int left_x = i;
            int left_y = i - 1;

            while (right_x >= 0) {
                int tp = matrix[left_x][left_y];
                matrix[left_x][left_y] = matrix[right_x][right_y];
                matrix[right_x][right_y] = tp;

                right_x--;
                left_y--;
            }
        }

    }
};

int main() {
    vector<vector<int>> nums = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution so;
    so.rotate(nums);
    for (auto as: nums) {
        for (auto a: as) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}