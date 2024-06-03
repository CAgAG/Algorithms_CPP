/*************************
 * @file   : 8_sum_of_four_numbers.cpp
 * @encode : UTF-8
 * @note   : 四数之和 https://leetcode.cn/problems/4sum/description/
 * @date   : 2024/3/2 15
 *************************/

#include "iostream"
#include "unordered_map"
#include "unordered_set"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // 固定 b, c, d, 对 a去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int a = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                // 固定 a, c, d, 对 b去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int b = nums[j];
                int left_index = j + 1;
                int right_index = nums.size() - 1;

                while (left_index < right_index) {
                    int c = nums[left_index];
                    int d = nums[right_index];

                    long sum_ = (long) a + b + c + d;  // 防止溢出
                    if (sum_ > target) {
                        right_index--;
                    } else if (sum_ < target) {
                        left_index++;
                    } else {
                        ret.push_back({a, b, c, d});
                        // 去重, 分别移动(去重) left_index 和 right_index 的区间
                        while (left_index < right_index && nums[left_index] == nums[left_index + 1]) left_index++;
                        while (left_index < right_index && nums[right_index] == nums[right_index - 1]) right_index--;

                        // 缩小区间
                        left_index++;
                        right_index--;
                    }
                }

            }
        }
        return ret;
    }
};


int main() {
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution so;
    vector<vector<int>> ret = so.fourSum(vec, target);
    for (auto it1: ret) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}