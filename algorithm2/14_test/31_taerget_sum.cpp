/*************************
 * @file   : 31_taerget_sum.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/15 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == abs(target)) {
                return 1;
            }
            return 0;
        }

        // left + right = sum
        // left - right = target
        // ==> 2 * left = sum + target
        // ==> left = (sum + target) / 2

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (abs(target) > sum) {
            return 0;
        }
        if ((sum + target) % 2 == 1) {
            return 0;
        }

        int bag_weight = (sum + target) / 2;
        vector<int> dp = vector<int>(bag_weight + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = bag_weight; j >= nums[i]; --j) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[bag_weight];
    }
};

int main() {
    vector<int> nums = {1};
    int t = 1;

    Solution so;

    cout << so.findTargetSumWays(nums, t) << endl;

    return 0;
}