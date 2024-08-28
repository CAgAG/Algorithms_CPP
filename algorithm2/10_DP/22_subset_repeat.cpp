/*************************
 * @file   : 22_subset_repeat.cpp
 * @encode : UTF-8
 * @note   : 最长重复子数组(连续) https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 * @date   : 2024/4/26 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        // dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]。
        // 注意: 这个定义下的 重复子数组 最后一位一定是 i-1，j-1所对应的数值
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int ret = 0;
        for (int i = 1; i <= nums1.size(); ++i) {  // 判断条件都是等号
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {  // 找到相等的字符
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // 一起回退到上一个的 最长重复子数组长度
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        return ret;
    }

    // =====================================================================
    // dp[i][j] ：以下标 i为结尾的A，和以下标 j为结尾的B，最长重复子数组长度为dp[i][j]。
    int findLength2(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ret = 0;

        // 要对第一行，第一列经行初始化
        for (int i = 0; i < nums1.size(); i++) if (nums1[i] == nums2[0]) dp[i][0] = 1;
        for (int j = 0; j < nums2.size(); j++) if (nums1[0] == nums2[j]) dp[0][j] = 1;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j] && i > 0 && j > 0) { // 防止 i-1 出现负数
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    Solution so;
    cout << so.findLength(nums, nums2) << endl;
    return 0;
}