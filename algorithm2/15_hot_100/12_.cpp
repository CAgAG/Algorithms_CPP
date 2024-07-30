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
    int m, n;

    bool traver(vector<vector<int>> &matrix, int target) {
        for (int i = 0; i < m; ++i) {

            int left_i = 0;
            int right_i = n - 1;
            while (left_i <= right_i) {
                int mid_i = (left_i + right_i) / 2;
                if (matrix[i][mid_i] == target) {
                    return true;
                } else if (matrix[i][mid_i] > target) {
                    right_i = mid_i - 1;
                } else {
                    left_i = mid_i + 1;
                }
            }

        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        return traver(matrix, target);
    }
};

int main() {
    vector<vector<int>> nums = {
            {1,   4,  7,  11, 15},
            {2,   5,  8,  12, 19},
            {3,   6,  9,  16, 22},
            {310, 13, 14, 17, 24},
            {18,  21, 23, 26, 30}
    };
    int target = 5;
    Solution so;
    cout << so.searchMatrix(nums, target) << endl;


    return 0;
}