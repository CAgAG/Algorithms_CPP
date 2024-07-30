/*************************
 * @file   : 42_.cpp
 * @encode : UTF-8
 * @note   : 环形子数组的最大和 https://leetcode.cn/problems/maximum-sum-circular-subarray/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/20 13
 *************************/

// https://leetcode.cn/problems/maximum-sum-circular-subarray/solutions/1152143/wo-hua-yi-bian-jiu-kan-dong-de-ti-jie-ni-892u/?envType=study-plan-v2&envId=top-interview-150

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int total_sum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int &a: nums) {
            // dp max
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            // dp min
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            // nums 数组的总和
            total_sum += a;
        }

        if (maxSum > 0) {
            return max(maxSum, total_sum - minSum);
        } else {
            return maxSum;
        }
    }
};

int main() {

    vector<int> nums = {3, -2, 2, -3};
    Solution so;
    cout << so.maxSubarraySumCircular(nums) << endl;

    return 0;
}