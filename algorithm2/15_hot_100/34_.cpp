/*************************
 * @file   : 34_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/25 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left_i = 0;
        int right_i = nums.size() - 1;

        while (left_i <= right_i) {
            int mid_i = (left_i + right_i) / 2;
            if (nums[mid_i] == target) {
                return mid_i;
            } else if (nums[mid_i] > target) {
                right_i = mid_i - 1;
            } else {
                left_i = mid_i + 1;
            }
        }
        return left_i;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target_num = 2;

    Solution so;
    cout << so.searchInsert(nums, target_num) << endl;

    return 0;
}