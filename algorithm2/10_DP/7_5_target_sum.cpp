/*************************
 * @file   : 7_target_sum.cpp
 * @encode : UTF-8
 * @note   : 目标和 https://leetcode.cn/problems/target-sum/description/
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
     * 只需要找出正数的集合
     */
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
        if (abs(target) > sum) return 0; // 此时没有方案
        if ((target + sum) % 2) return 0; // 奇数, 此时没有方案，看推导得出，left的值不可能是小数

        int bag_weight = (target + sum) / 2;
        // cout << bag_weight << endl;
        vector<int> dp(bag_weight + 1, 0);
        // dp[j]: 装满容量为j的背包有dp[j]种方法
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag_weight; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
                // cout << j << ", " << j - nums[i] << endl;
                /* dp[j] 选择物品 nums[i] 加入背包
                 * dp[j-nums[i]] 不选择物品 nums[i] 加入背包
                 * 注意此处求的是方法数
                 */
            }
        }
        return dp[bag_weight];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};

    Solution so;
    cout << so.findTargetSumWays(nums, 3) << endl;
    return 0;
}