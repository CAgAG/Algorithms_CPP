/*************************
 * @file   : 23_.cpp
 * @encode : UTF-8
 * @note   : 汇总区间 https://leetcode.cn/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/14 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "strings.h"

using namespace std;


class Solution {
public:
    bool check(int num1, int num2) {  // 是否不连续
        // num1 > num2
        // abs(abs(cur_num) - abs(pre_num)) > 1
        if (num1 < 0 && num2 > 0) {
            return true;
        } else if (num1 > 0 && num2 < 0) {
            return true;
        } else if (num1 < 0 && num2 < 0) {
            return abs(abs(num1) - abs(num2)) > 1;
        } else {
            return (num1 - num2) > 1;
        }
    }

    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ret;

        int n = nums.size();
        if (n == 0) {
            return ret;
        } else if (n == 1) {
            ret.push_back(to_string(nums[0]));
            return ret;
        }

        int left_i = 0;
        int right_i = 1;

        while (right_i < n) {
            int cur_num = nums[right_i];
            int pre_num = nums[right_i - 1];

            if (check(cur_num, pre_num)) {  // 不连续
                if (right_i - 1 == left_i) {
                    ret.push_back(to_string(nums[left_i]));
                    left_i++;
                    right_i++;
                } else {
                    ret.push_back(to_string(nums[left_i]) + "->" + to_string(nums[right_i - 1]));
                    left_i = right_i;
                    right_i++;
                }
            } else {
                right_i++;
            }
        }

        if (right_i - 1 == left_i) {
            ret.push_back(to_string(nums[left_i]));
        } else {
            ret.push_back(to_string(nums[left_i]) + "->" + to_string(nums[right_i - 1]));
        }

        return ret;
    }
};

int main() {

    vector<int> nums = {-2147483648, -2147483647, 2147483647};

    Solution so;

    for (auto c: so.summaryRanges(nums)) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}