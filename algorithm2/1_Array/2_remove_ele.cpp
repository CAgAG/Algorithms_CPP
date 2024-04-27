/*************************
 * @file   : 2_remove_ele.cpp
 * @encode : UTF-8
 * @note   : 移除元素 https://leetcode.cn/problems/remove-element/description/
 * @date   : 2024/2/29 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    /* 时间复杂度：O(n) */
    int removeElement(vector<int>& nums, int val) {
        int slow_point = 0;  // 之前的数组是不含 val的, 也是数据更新的位置
        for (int fast_point = 0; fast_point < nums.size(); ++fast_point) {  // 寻找新数组的元素, 新数组就是不含有目标元素的数组
            if (nums[fast_point] != val) {
                nums[slow_point] = nums[fast_point];
                slow_point += 1;
            }
            // 如果遇到与 val相等的值就只更新 fast_point
        }
        return slow_point;
    }
};

int main() {

    Solution so;

    vector<int> vec = {3, 2, 2, 3};
    int val = 2;

    cout << so.removeElement(vec, val) << endl;
    return 0;
}