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
    int bin_search(vector<int> &nums, int target) {
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
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int index = bin_search(nums, target);

        if (index == -1) {
            return {-1, -1};
        }

        int left_index = index;
        int right_index = index;
        // 向左找
        while (left_index >= 0 && nums[left_index] == target) {
            left_index--;
        }
        // 向右找
        while (right_index < nums.size() && nums[right_index] == target) {
            right_index++;
        }

        return {left_index + 1, right_index - 1};
    }
};

int main() {
    vector<int> nums = {1};
    int target_num = 1;

    Solution so;
    vector<int> ret = so.searchRange(nums, target_num);
    cout << ret[0] << ", " << ret[1] << endl;

    return 0;
}