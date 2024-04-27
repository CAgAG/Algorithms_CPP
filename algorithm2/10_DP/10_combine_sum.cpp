/*************************
 * @file   : 10_combine_sum.cpp
 * @encode : UTF-8
 * @note   : 组合总和 Ⅳ https://leetcode.cn/problems/combination-sum-iv/description/
 * @date   : 2024/4/23 19
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int bag_weight = target;
        vector<int> dp(bag_weight + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= bag_weight; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                // C++测试用例有两个数相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]
                if (j - nums[i] >= 0 &&
                    dp[j] < INT_MAX - dp[j - nums[i]]) {
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
            }
        }
        return dp[bag_weight];
    }
};

int main() {
    int target = 4;
    vector<int> nums = {1, 2, 3};

    Solution so;
    cout << so.combinationSum4(nums, target) << endl;

    return 0;
}
