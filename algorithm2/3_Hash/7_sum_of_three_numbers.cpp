/*************************
 * @file   : 7_sum_of_three_nums.cpp
 * @encode : UTF-8
 * @note   : 三数之和 https://leetcode.cn/problems/3sum/description/
 * @date   : 2024/3/2 13
 *************************/

#include "iostream"
#include "unordered_map"
#include "unordered_set"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    //  a + b + c = 0 ？
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        // {-4, -1, -1, 0, 1, 2}
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // 当 b和 c固定时, 对 a值去重
            if (i > 0 && nums[i] == nums[i - 1]) {  // 此处不能是 i 和 i+1, 因为那代表的是 a和 c, 这两个是有可能相等的
                continue;
            }

            int a = nums[i];
            unordered_set<int> set;  // 存储有可能的 b值
            for (int k = i + 1; k < nums.size(); ++k) {
                // 当 a和 b固定时, 对 c值去重
                if (k > i + 2
                    && nums[k] == nums[k - 1]  // 如果 c 和 c的前一个也相等
                    && nums[k - 1] == nums[k - 2]) {  // {0, 0, 0, 0}
                    /* i i+1 i+2 i+3
                     * a     b   c
                     * a b       c
                     * * * * * * * *
                     * i i+1 i+2 i+3 i+4
                     * a             c
                     */
                    continue;
                }

                int c = nums[k];
                int b = 0 - (a + c);
                if (set.find(b) != set.end()) {
                    ret.push_back({a, b, c});
                    set.erase(b);  // 对 b值去重
                } else {
                    set.insert(nums[k]);  // 存储有可能的 b值
                }
            }
        }
        return ret;
    }

    // 双指针法
    vector<vector<int>> threeSum2(vector<int> &nums) {
        vector<vector<int>> ret;
        // {-4, -1, -1, 0, 1, 2}
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // 当 b和 c固定时, 对 a值去重
            if (i > 0 && nums[i] == nums[i - 1]) {  // 此处不能是 i 和 i+1, 因为那代表的是 a和 c, 这两个是有可能相等的
                continue;
            }

            int a = nums[i];
            int left_index = i + 1;
            int right_index = nums.size() - 1;
            while (left_index < right_index) {
                int b = nums[left_index];
                int c = nums[right_index];

                int sum_ = a + b + c;  // 逼近目标值
                if (sum_ > 0) {
                    right_index--;
                } else if (sum_ < 0) {
                    left_index++;
                } else {
                    ret.push_back({a, b, c});
                    // 缩小指针范围, 去重
                    while (left_index < right_index && nums[left_index] == nums[left_index + 1]) left_index++;
                    while (left_index < right_index && nums[right_index] == nums[right_index - 1]) right_index--;

                    left_index++;
                    right_index--;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> vec = {-1, 0, 1, 2, -1, -4};

    Solution so;
    vector<vector<int>> ret = so.threeSum(vec);
    for (auto it1: ret) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    cout << "====================" << endl;

    vector<vector<int>> ret2 = so.threeSum2(vec);
    for (auto it1: ret2) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}