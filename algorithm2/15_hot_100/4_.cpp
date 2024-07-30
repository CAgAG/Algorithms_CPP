/*************************
 * @file   : 4_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    // 贪心
    int maxArea(vector<int> &height) {
        int n = height.size();
        int right_i = n - 1;
        int left_i = 0;
        int ret = 0;

        while (left_i <= right_i) {

            int area = min(height[left_i], height[right_i]) * (right_i - left_i);  // 看计算公式
            ret = max(ret, area);

            // 保证高度
            // 总是移动数字较小的那个指针
            if (height[right_i] > height[left_i]) {
                left_i++;
            } else {
                right_i--;
            }
        }

        return ret;
    }
};

int main() {

    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution so;
    cout << so.maxArea(nums) << endl;

    return 0;
}