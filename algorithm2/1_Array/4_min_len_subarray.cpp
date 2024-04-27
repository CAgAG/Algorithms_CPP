/*************************
 * @file   : 4_min_len_subarray.cpp
 * @encode : UTF-8
 * @note   : 长度最小的子数组 https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 * @date   : 2024/2/29 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ret = INT32_MAX;
        int length = nums.size() - 1;
        int window_left = 0, window_right = 0, window_sum=0;
        while (window_right <= length) {
            // 以右边的指针为锚定
            int cur_num = nums[window_right];
            window_sum += cur_num;

            while (window_sum >= target) {
                int sub_length =  window_right - window_left + 1;
                ret = min(ret, sub_length);

                window_sum -= nums[window_left];
                window_left += 1;  // 参试移动左边的指针缩小范围
            }
            window_right += 1;
        }
        return ret == INT32_MAX ? 0: ret;
    }
};

int main() {

    Solution so;

    vector<int> vec = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << so.minSubArrayLen(target, vec) << endl;
    return 0;
}