/*************************
 * @file   : 7_target_sum.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/4/23 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
    /* 既然为target，那么就一定有 left组合 - right组合 = target。 (注意: left和right组合都可以为空)
     * left + right = sum，而sum是固定的。right = sum - left
     * 公式来了， left - (sum - left) = target 推导出 left = (target + sum)/2 。
     * target是固定的，sum是固定的，left就可以求出来。
     * 此时问题就是在集合nums中找出和为left的组合。
     */
private:
    int ret = 0;

    void backtrace(vector<int> &nums, int target, int start_index, int cur_sum) {
        if (cur_sum == target) {
            ret++;
        }

        for (int i = start_index; i < nums.size(); ++i) {
            cur_sum += nums[i];
            backtrace(nums, target, i + 1, cur_sum);
            cur_sum -= nums[i];
        }

    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target || -1 * nums[0] == target) {
                return 1;
            }
            return 0;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (target > sum) return 0; // 此时没有方案
        if ((target + sum) % 2) return 0; // 奇数, 此时没有方案，看推导得出，left的值不可能是小数
        int new_t = (target + sum) / 2;

        backtrace(nums, new_t, 0, 0);
        return ret;
    }
};

int main() {
    vector<int> nums = {7, 9, 3, 8, 0, 2, 4, 8, 3, 9};

    Solution so;
    cout << so.findTargetSumWays(nums, 0) << endl;
    return 0;
}