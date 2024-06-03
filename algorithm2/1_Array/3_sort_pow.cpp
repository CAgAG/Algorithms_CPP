/*************************
 * @file   : 3_sort_pow.cpp
 * @encode : UTF-8
 * @note   : 有序数组的平方 https://leetcode.cn/problems/squares-of-a-sorted-array/
 * @date   : 2024/2/29 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    /* 时间复杂度为 O(n) */
    // 双指针
    // 从两边向中间 移动
    vector<int> sortedSquares(vector<int> &nums) {  // 数组其实是有序的, 那么数组平方的最大值就在数组的两端
        int left_point = 0, right_point = nums.size() - 1;  // 从两边找最大值
        vector<int> ret(nums.size());  // ret 的最后一位始终是最大的数
        int ret_index = ret.size() - 1;

        while (left_point <= right_point) {
            int left_num = nums[left_point];
            left_num = left_num * left_num;

            int right_num = nums[right_point];
            right_num = right_num * right_num;

            if (right_num > left_num) {
                ret[ret_index] = right_num;
                right_point -= 1;
            } else {
                ret[ret_index] = left_num;
                left_point += 1;
            }
            ret_index -= 1;
        }
        return ret;
    }
};

void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {

    Solution so;

    vector<int> vec = {4, -1, 0, 3, 10};

    print_vector(so.sortedSquares(vec));
    return 0;
}