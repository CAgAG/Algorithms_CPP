/*************************
 * @file   : 43_subset_longer.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/17 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // 0.。i-1 0..j-1
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        int ret = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {

                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);
                }

            }
        }

        return ret;
    }
};

int main() {
    vector<int> num1 = {1, 2, 3, 2, 1};
    vector<int> num2 = {3, 2, 1, 4, 7};

    Solution so;
    cout << so.findLength(num1, num2) << endl;

    return 0;
}