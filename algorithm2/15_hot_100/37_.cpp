/*************************
 * @file   : 34_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/25 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size() - 1;
        int left_i = 0;
        int right_i = n;
        while (left_i <= right_i) {
            int mid_i = (left_i + right_i) / 2;
            int cur_mid = nums[mid_i];

            if (cur_mid == target) {
                return mid_i;
            }

            // 实际的左右边界和移动的左右边界是分开的
            // 实际的左右边界不变, 只移动了 mid
            if (nums[0] <= cur_mid) {  // 说明左区间是有序的 [0, .., mid, ..., end]
                if (nums[0] <= target && target < cur_mid) {
                    right_i = mid_i - 1;
                } else {
                    left_i = mid_i + 1;
                }

            } else {  // 否则右区间是有序的  [0, .., mid, ..., end]
                if (cur_mid < target && target <= nums[n]) {
                    left_i = mid_i + 1;
                } else {
                    right_i = mid_i - 1;
                }

            }
        }
        return -1;

    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target_num = 0;

    Solution so;
    cout << so.search(nums, target_num) << endl;

    return 0;
}