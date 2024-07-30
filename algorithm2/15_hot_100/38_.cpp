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
    int findMin(vector<int> &nums) {

        int n = nums.size() - 1;
        // 最小值所在的区间
        int left_i = 0;
        int right_i = n;
        int ret = INT_MAX;

        while (left_i <= right_i) {
            int mid_index = (left_i + right_i) / 2;

            ret = min(ret, nums[mid_index]);
            if (nums[mid_index] < nums[right_i]) {
                right_i = mid_index - 1;
            } else {
                left_i = mid_index + 1;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    Solution so;
    cout << so.findMin(nums) << endl;

    return 0;
}