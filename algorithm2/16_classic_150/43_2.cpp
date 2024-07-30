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
    // 总的一句话，往递增的方向上，二分，一定能找到，往递减的方向只是可能找到，也许没有。
    int findPeakElement(vector<int> &nums) {

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;

            // 爬坡
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};

int main() {
    vector<int> nums = {-2147483648};

    Solution so;
    cout << so.findPeakElement(nums) << endl;

    return 0;
}
