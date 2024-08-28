/*************************
 * @file   : 13_last_stone.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/10 11
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {

        if (stones.size() == 1) {
            return stones[0];
        }

        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) {
            sum += stones[i];
        }

        int bag_weight = sum / 2;

        vector<int> dp = vector<int>(bag_weight + 1, 0);

        for (int i = 0; i < stones.size(); ++i) {
            for (int j = bag_weight; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[bag_weight];
    }
};


int main() {

    vector<int> s = {31,26,33,21,40};
    Solution so;
    cout << so.lastStoneWeightII(s) << endl;

    return 0;
}