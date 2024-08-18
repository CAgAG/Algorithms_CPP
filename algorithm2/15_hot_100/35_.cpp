/*************************
 * @file   : 34_.cpp
 * @encode : UTF-8
 * @note   : 搜索二维矩阵 https://leetcode.cn/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-100-liked
 * @date   : 2024/6/25 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool bin_search(vector<int> &matrix, int target) {
        int left_i = 0;
        int right_i = matrix.size() - 1;

        while (left_i <= right_i) {
            int mid_i = (left_i + right_i) / 2;

            if (matrix[mid_i] == target) {
                return true;
            } else if (matrix[mid_i] > target) {
                right_i = mid_i - 1;
            } else {
                left_i = mid_i + 1;
            }
        }
        return false;

    }


    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();

        // 按行二分查找
        for (int i = 0; i < m; ++i) {
            if (bin_search(matrix[i], target)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> nums = {
            {1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 60}
    };
    int target_num = 3;

    Solution so;
    cout << so.searchMatrix(nums, target_num) << endl;

    return 0;
}