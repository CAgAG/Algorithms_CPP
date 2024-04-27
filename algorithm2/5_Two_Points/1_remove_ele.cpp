/*************************
 * @file   : 1_remove_ele.cpp
 * @encode : UTF-8
 * @note   : 移除元素 https://leetcode.cn/problems/remove-element/description/
 * @date   : 2024/3/4 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int slow_point = 0;  // 慢指针之前的数组不包含 val, 同时也是下一个要交换的元素
        int fast_point = 0;  // 快指针负责查找 不等于 val 的元素加入到 慢指针所指向的数组中
        for (slow_point = 0, fast_point = 0; fast_point < nums.size(); ++fast_point) {
            if (nums[fast_point] != val) {
                nums[slow_point] = nums[fast_point];
                slow_point++;
            }
        }
        return slow_point;
    }
};

int main() {
    vector<int> vec = {3, 2, 3, 3, 3, 2, 3};

    Solution so;
    int new_size = so.removeElement(vec, 3);
    cout << new_size << endl;
    for (int i = 0; i < new_size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}