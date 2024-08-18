/*************************
 * @file   : 8_.cpp
 * @encode : UTF-8
 * @note   : 删除有序数组中的重复项 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/7 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int cur_i = 1;
        // cur_i, ..., i-1, i
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {  // 不重复的元素
                nums[cur_i] = nums[i];
                cur_i++;
            }
        }
        return cur_i;
    }
};

int main() {

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution so;
    int len = so.removeDuplicates(nums);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}