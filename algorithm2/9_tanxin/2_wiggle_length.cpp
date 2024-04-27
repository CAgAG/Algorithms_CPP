/*************************
 * @file   : 2_wiggle_length.cpp
 * @encode : UTF-8
 * @note   : 摆动序列 https://leetcode.cn/problems/wiggle-subsequence/description/
 * @date   : 2024/4/8 20
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int ret = 1;
        int cur_diff = 0;  // 当前差值
        int pre_diff = 0;  // 上一个差值

        for (int i = 0; i < nums.size() - 1; ++i) {
            cur_diff = nums[i + 1] - nums[i];
            // 摆动序列
            if ((pre_diff <= 0 && cur_diff > 0) || (pre_diff >= 0 && cur_diff < 0)) {  // 通过 与 和 或 来控制交错的顺序
                ret++;
                // 只在摆动变化的时候更新 pre_diff
                pre_diff = cur_diff;
            }
        }
        return ret;
    }
};


int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4};

    Solution so;
    cout << so.wiggleMaxLength(nums) << endl;

    return 0;
}
