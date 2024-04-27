/*************************
 * @file   : 5_split_equal_subset.cpp
 * @encode : UTF-8
 * @note   : 分割等和子集 https://leetcode.cn/problems/partition-equal-subset-sum/description/
 * @date   : 2024/4/22 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 只要找到集合里能够出现 sum / 2 的子集总和，就算是可以分割成两个相同元素和子集了


class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        // 奇数求不了
        if (sum % 2 == 1) return false;

        int bag_weight = sum / 2;
        vector<int> dp(bag_weight + 1, 0);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = bag_weight; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[bag_weight] == bag_weight) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 5};

    Solution so;
    cout << so.canPartition(nums) << endl;

    return 0;
}