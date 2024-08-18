/*************************
 * @file   : 7_.cpp
 * @encode : UTF-8
 * @note   : 除自身以外数组的乘积 https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked
 * @date   : 2024/6/21 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> left = vector<int>(n, 0);  // 除 i 以外左边的乘积
        vector<int> right = vector<int>(n, 0);  // 除 i 以外右边的乘积

        left[0] = 1;
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> ans = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution so;
    vector<int> nums2 = so.productExceptSelf(nums);

    for (int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}