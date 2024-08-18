/*************************
 * @file   : 49_.cpp
 * @encode : UTF-8
 * @note   : 寻找重复数 https://leetcode.cn/problems/find-the-duplicate-number/?envType=study-plan-v2&envId=top-100-liked
 * @date   : 2024/6/27 19
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool bin_search(vector<int> &nums, int left_i, int right_i, int target) {
        while (left_i <= right_i) {
            int mid = (left_i + right_i) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] > target) {
                right_i = mid - 1;
            } else {
                left_i = mid + 1;
            }
        }
        return false;
    }

    // 只有 一个重复的整数 ，返回 这个重复的数
    int findDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int cur_num = nums[i];

            bool f1 = bin_search(nums, 0, i - 1, cur_num);  // 不包括 i的左边，查找重复值
            bool f2 = bin_search(nums, i + 1, nums.size() - 1, cur_num);  // 不包括 i的右边，查找重复值
            if (f1 || f2) {  // 只要有一个就返回
                return cur_num;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums{1, 3, 4, 2, 2};

    Solution so;
    cout << so.findDuplicate(nums) << endl;

    return 0;
}