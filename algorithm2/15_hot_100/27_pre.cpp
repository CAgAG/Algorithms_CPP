/*************************
 * @file   : 27_pre.cpp
 * @encode : UTF-8
 * @note   : 560. 和为 K 的子数组https://leetcode.cn/problems/subarray-sum-equals-k/description/
 * @date   : 2024/6/23 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

// 已知原数组 存在前缀和 = c, 目标和 k
// [1, 2, ..., a, ..., c] +
// 如果存在 a 使得 a + k = c  ==> c - k = a
// 那么 k 必在原数组中存在

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        // 前缀和
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        int ret = 0;
        map<int, int> mp;  // 前缀和, 数量(原数组可能存在负数)
        for (int i = 0; i < prefix_sum.size(); ++i) {  // 遍历前缀和: c
            int ps = prefix_sum[i];
            if (mp.find(ps - k) != mp.end()) { // a 是否存在
                ret += mp[ps - k];
            }
            mp[ps]++;
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 1, 4};
    int k = 2;

    Solution so;
    cout << so.subarraySum(nums, k) << endl;

    return 0;
}