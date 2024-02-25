/*************************
 * @file   : example2.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/16 12
 *************************/

/* 给一个序列，求它的最长上升子序列。
 * 子序列是将序列删除0-n个元素所组成的序列
 * 1 13 5 7 8 2 11
 * 1 5 7 8 11  -> 删除 13 2
 * */

#include "vector"
#include "iostream"

using namespace std;

// 动态规划求解最长上升子序列
int longest_increasing_subsequence(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);  // 初始化dp数组，每个元素至少为1
    int max_len = 1;  // 最长上升子序列的长度

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {  // 确保序列是上升的
                dp[i] = max(dp[i], dp[j] + 1);  // +1 是加 i本身
            }
        }
        max_len = max(max_len, dp[i]);
    }

    return max_len;
}

// 动态规划和二分查找
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp; // 存储当前最长上升子序列
    for (int num : nums) {
        // 在 dp 中找到第一个大于 num 的元素的位置
        auto it = lower_bound(dp.begin(), dp.end(), num);
        // 如果找到了，则替换为 num
        // 如果没有找到，则插入到正确的位置以保持 dp 的有序性
        if (it == dp.end()) {  // 没有找到, 那这个数就是 dp 数组中目前最大的数
            dp.push_back(num); // 插入到末尾，形成一个更长的子序列
        } else {
            *it = num;  // 覆盖了正确的序列的数也无所谓, 因为要的是长度, 把长度留下就行
        }
    }
    return dp.size(); // dp 的大小就是最长上升子序列的长度
}

int main() {
    vector<int> nums = {1, 13, 5, 7, 8, 2, 11};

    // 定义状态
    // f(i)表示以 i结尾的上升子序列中的最长长度
    cout << longest_increasing_subsequence(nums) << endl;
    cout << lengthOfLIS(nums) << endl;

    return 0;
}