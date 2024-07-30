/*************************
 * @file   : 39_.cpp
 * @encode : UTF-8
 * @note   : 蛇梯棋 https://leetcode.cn/problems/snakes-and-ladders/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/19 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"
#include "set"

using namespace std;

class Solution {
public:
    map<int, pair<int, int>> board_map;  // 数值与左边的映射

    int snakesAndLadders(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();
        int goal = m * n;
        // 传送门的坐标
        vector<pair<int, int>> gate_pos;
        // 值与坐标的映射
        bool flag = true;
        int cur_num = 1;
        for (int i = m - 1; i >= 0; --i) {
            if (flag) {
                for (int j = 0; j < n; ++j) {
                    board_map[cur_num] = {i, j};
                    cur_num++;
                    if (board[i][j] != -1) {
                        gate_pos.push_back({i, j});
                    }
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    board_map[cur_num] = {i, j};
                    cur_num++;
                    if (board[i][j] != -1) {
                        gate_pos.push_back({i, j});
                    }
                }
            }

            flag = !flag;
        }

        // 广度搜索
        queue<vector<int>> que;  // 数值和操作次数
        que.push({1, 0});
        vector<bool> visited(goal + 1, false);

        while (!que.empty()) {
            auto cur_p = que.front();
            que.pop();

            int cur_num = cur_p[0];
            int cur_op_count = cur_p[1];

            // 注意: 如果目标方格 next 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地
            // 摇色子  --> 下一个位置
            for (int next_num = cur_num + 1; next_num <= min(goal, cur_num + 6); ++next_num) {
                // 下一步的坐标
                int trans_num = next_num;
                int trans_x = board_map[trans_num].first;
                int trans_y = board_map[trans_num].second;

                // 如果有传送门, 直接使用
                if (board[trans_x][trans_y] != -1) {
                    // 更新
                    trans_num = board[trans_x][trans_y];
                    trans_x = board_map[trans_num].first;
                    trans_y = board_map[trans_num].second;
                }
                // 正好是终点
                if (trans_num == goal) {
                    return cur_op_count + 1;
                }
                // 只传送到 【未访问过的位置】
                if (visited[trans_num] == false) {
                    visited[trans_num] = true;
                    que.push({trans_num, cur_op_count + 1});
                }

            }

        }

        return -1;
    }
};


int main() {
    vector<vector<int>> board = {
            {-1, -1,  -1,  30, -1,  144, 124, 135, -1, -1,  -1, -1,  -1},
            {-1, -1,  -1,  -1, -1,  -1,  167, 93,  -1, -1,  -1, -1,  -1},
            {-1, -1,  -1,  -1, -1,  -1,  -1,  77,  -1, -1,  90, -1,  -1},
            {-1, -1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1,  -1, -1,  -1},
            {-1, -1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1,  -1, 122, -1},
            {-1, -1,  -1,  23, -1,  -1,  -1,  -1,  -1, 155, -1, -1,  -1},
            {-1, -1,  140, 29, -1,  -1,  -1,  -1,  -1, -1,  -1, -1,  -1},
            {-1, -1,  -1,  -1, -1,  115, -1,  -1,  -1, 109, -1, -1,  5},
            {-1, 57,  -1,  99, 121, -1,  -1,  132, -1, -1,  -1, -1,  -1},
            {-1, 48,  -1,  -1, -1,  68,  -1,  -1,  -1, -1,  31, -1,  -1},
            {-1, 163, 147, -1, 77,  -1,  -1,  114, -1, -1,  80, -1,  -1},
            {-1, -1,  -1,  -1, -1,  57,  28,  -1,  -1, 129, -1, -1,  -1},
            {-1, -1,  -1,  -1, -1,  -1,  -1,  -1,  -1, 87,  -1, -1,  -1}
    };

    Solution so;
    cout << so.snakesAndLadders(board) << endl;

    return 0;
}