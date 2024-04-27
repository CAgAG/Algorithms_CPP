/*************************
 * @file   : 5_jump_game.cpp
 * @encode : UTF-8
 * @note   : 跳跃游戏 I https://leetcode.cn/problems/jump-game/
 * @date   : 2024/4/11 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }

        int pre_max_length = 0;
        int end = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            int cur_max_jump = nums[i];
            // 当前无法跳跃 且 历史最大距离也小于当前位置
            if (cur_max_jump == 0 && pre_max_length <= i) {
                return false;
            }
            // 计算当前能够到达的最大距离
            int cur_max_length = i + cur_max_jump;
            if (cur_max_length >= end) {
                return true;
            }
            // 保存历史最长距离
            if (cur_max_length > pre_max_length) {
                pre_max_length = cur_max_length;
            }
        }
        return false;
    }

    // =============================================
    // 不用拘泥于每次究竟跳几步，而是看覆盖范围，覆盖范围内一定是可以跳过来的，不用管是怎么跳的
    bool canJump2(vector<int> &nums) {
        // 只有一个元素，就是能达到
        if (nums.size() == 1) {
            return true;
        }

        int cover = 0;
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            // 说明可以覆盖到终点了
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> num = {2, 3, 1, 1, 4};

    Solution so;
    cout << so.canJump(num) << endl;

    return 0;
}