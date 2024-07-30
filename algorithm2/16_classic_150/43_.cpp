/*************************
 * @file   : 43_.cpp
 * @encode : UTF-8
 * @note   : 寻找峰值 https://leetcode.cn/problems/find-peak-element/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/21 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {

        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int border_num = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int cur_num = nums[i];
            int left_num = border_num;
            int right_num = border_num;
            if (i - 1 >= 0) {
                left_num = nums[i - 1];
            }
            if (i + 1 < n) {
                right_num = nums[i + 1];
            }

            if (cur_num > left_num && cur_num > right_num) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-2147483648};

    Solution so;
    cout << so.findPeakElement(nums) << endl;

    return 0;
}
