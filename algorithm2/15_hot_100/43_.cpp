/*************************
 * @file   : 43_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/26 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {

        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int ret = nums[0];
        // 到 dp[i]的最大子数组乘积
        vector<int> dp(n + 1, 0);
        vector<int> dp2(n + 1, 0);
        dp[0] = nums[0];
        dp2[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            // 记录最小值
            dp2[i] = min(dp2[i - 1] * nums[i], min(nums[i], dp[i - 1] * nums[i]));
            dp[i] = max(dp[i - 1] * nums[i], max(nums[i], dp2[i - 1] * nums[i]));

            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {

    vector<int> nums = {-2, 3, -4};
    Solution so;
    cout << so.maxProduct(nums) << endl;

    return 0;
}