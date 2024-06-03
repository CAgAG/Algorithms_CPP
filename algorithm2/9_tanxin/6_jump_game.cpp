/*************************
 * @file   : 6_jump_game.cpp
 * @encode : UTF-8
 * @note   : 跳跃游戏 II https://leetcode.cn/problems/jump-game-ii/description/
 * @date   : 2024/4/11 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 统计两个覆盖范围，当前这一步的最大覆盖和下一步最大覆盖。

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        // 历史可达的最大距离
        int cur_distance = 0;
        int ret = 0;
        int next_distance = 0;  // 当前到 历史可达的最大距离之间，动态可达的最大距离
        for (int i = 0; i < nums.size(); ++i) {
            // 到 cur_distance 之前, 能够到达的最大距离
            next_distance = max(nums[i] + i, next_distance);
            if (i == cur_distance) {
                // 更新历史可达的最大距离
                cur_distance = next_distance;
                ret++;
                if (next_distance >= nums.size() - 1) {
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> num = {2, 3, 1, 1, 4};

    Solution so;
    cout << so.jump(num) << endl;

    return 0;
}