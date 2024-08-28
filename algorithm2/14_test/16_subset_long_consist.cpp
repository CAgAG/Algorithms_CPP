/*************************
 * @file   : 16_subset_long_consist.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/11 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        int ret = 0;

        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {

                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    ret = max(ret, dp[i][j]);
                }

            }
        }

        return ret;
    }
};

int main() {
    vector<int> n1 = {1, 2, 3, 2, 1};
    vector<int> n2 = {3, 2, 1, 4, 7};

    Solution so;
    cout << so.findLength(n1, n2) << endl;

    return 0;
}
