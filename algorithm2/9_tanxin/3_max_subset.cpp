/*************************
 * @file   : 3_max_subset.cpp
 * @encode : UTF-8
 * @note   : 最大子序和 https://leetcode.cn/problems/maximum-subarray/description/
 * @date   : 2024/4/9 11
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ret = INT32_MIN;
        int cur_max_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cur_max_sum += nums[i];
            if (cur_max_sum > ret) {
                ret = cur_max_sum;
            }
            // 和 尽可能大于 0
            // 否则 重置
            if (cur_max_sum < 0) {
                cur_max_sum = 0;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution so;
    cout << so.maxSubArray(nums) << endl;

    return 0;
}