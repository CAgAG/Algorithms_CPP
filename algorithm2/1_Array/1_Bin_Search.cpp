/*************************
 * @file   : 1_Bin_Search.cpp
 * @encode : UTF-8
 * @note   : 二分查找 https://leetcode.cn/problems/binary-search/description/
 * @date   : 2024/2/29 09
 *************************/

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    /* 时间复杂度：O(log n)
     * 空间复杂度：O(1) */
    int search(vector<int> &nums, int target) {
        int mid = 0;
        int left = 0, right = nums.size() - 1;
        // 针对只有一个元素的情况
        if (nums.size() == 1) {
            if (nums[mid] == target) {
                return 0;
            } else {
                return -1;
            }
        }

        while (left <= right) {  //  target 是在一个在左闭右闭的区间里，也就是[left, right]
            mid = (left + right) / 2;
            // mid = left + (right - left) / 2;  // 不容易溢出
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] <= target) {
                left = mid + 1;
            } else { // 当前这个nums[mid]一定不是target，那么接下来要查找的左区间结束下标位置就是 mid - 1
                right = mid - 1;
            }

        }
        return -1;
    }
};

int main() {
    Solution so;

    vector<int> vec = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << so.search(vec, target) << endl;
}