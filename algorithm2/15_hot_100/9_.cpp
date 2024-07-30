/*************************
 * @file   : 9_.cpp
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
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) {
                    continue;
                }
                visited[i][j] = true;
                if (matrix[i][j] == 0) {
                    // 行
                    for (int k = 0; k < n; ++k) {
                        if (matrix[i][k] != 0) {
                            visited[i][k] = true;
                        }
                        matrix[i][k] = 0;
                    }
                    // 列
                    for (int k = 0; k < m; ++k) {
                        if (matrix[k][j] != 0) {
                            visited[k][j] = true;
                        }
                        matrix[k][j] = 0;
                    }
                }

            }

        }

    }
};

int main() {

    vector<vector<int>> nums = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
    };

    Solution so;
    so.setZeroes(nums);

    int m = nums.size();
    int n = nums[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}