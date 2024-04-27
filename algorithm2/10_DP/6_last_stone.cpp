/*************************
 * @file   : 6_last_stone.cpp
 * @encode : UTF-8
 * @note   : 最后一块石头的重量II https://leetcode.cn/problems/last-stone-weight-ii/description/
 * @date   : 2024/4/23 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {

        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) {
            sum += stones[i];
        }

        int bag_weight = sum / 2;
        // 最后dp[target]里是容量为target的背包所能背的最大重量
        vector<int> dp(bag_weight + 1, 0);

        for (int i = 0; i < stones.size(); ++i) {
            for (int j = bag_weight; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        // 在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。
        return sum - 2 * dp[bag_weight];
    }
};

int main() {
    vector<int> nums = {2, 7, 4, 1, 8, 1};

    Solution so;
    cout << so.lastStoneWeightII(nums) << endl;
    return 0;
}