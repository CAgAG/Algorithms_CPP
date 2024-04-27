/*************************
 * @file   : 4_sum_of_two_numbers.cpp
 * @encode : UTF-8
 * @note   : 两数之和 https://leetcode.cn/problems/two-sum/description/
 * @date   : 2024/3/2 11
 *************************/
/* 只会存在一个有效答案 */

#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;  // 记录出现 nums 数字的 index
        /* 这两个数的肯定是两个不同 index的数 */
        for (int i = 0; i < nums.size(); ++i) {
            int it = nums[i];
            if (map.find(target - it) != map.end()) {  // 直接对答案进行搜索
                return {map[target - it], i};
            }
            map[it] = i;
        }
        return {};
    }
};

int main() {
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;

    Solution so;
    vector<int> ret = so.twoSum(vec, target);
    for (int it: ret) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}