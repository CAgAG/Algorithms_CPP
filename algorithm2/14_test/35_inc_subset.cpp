/*************************
 * @file   : 35_inc_subset.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/15 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {

        // dp[i]: 到i之前的递增序列的长度
        int n = nums.size();
        int ret = 0;
        vector<int> dp = vector<int>(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {

                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);

                }
                ret = max(ret, dp[i]);

            }
        }
        return ret;
    }
};


int main() {
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};

    Solution so;
    cout << so.lengthOfLIS(nums) << endl;

    return 0;
}