/*************************
 * @file   : 19_.cpp
 * @encode : UTF-8
 * @note   : 生命游戏 https://leetcode.cn/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/12 12
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int m = 0;
    int n = 0;

    bool is_valid(int x, int y) {
        if (x < 0 || y < 0) {
            return false;
        }
        if (x >= m || y >= n) {
            return false;
        }
        return true;
    }

    int live_num(int x, int y, vector<vector<int>> &board) {
        int ret = 0;

        int start_x = x - 1;
        int start_y = y - 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int cur_x = start_x + i;
                int cur_y = start_y + j;
                if (cur_x == x && cur_y == y) {
                    continue;
                }
                if (is_valid(cur_x, cur_y) && board[cur_x][cur_y] == 1) {
                    ret++;
                }
            }
        }
        return ret;
    }

    void gameOfLife(vector<vector<int>> &board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> ret = vector<vector<int>>(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[i][j] = board[i][j];

                if (board[i][j] == 0) {  // 死细胞
                    if (live_num(i, j, board) == 3) {
                        ret[i][j] = 1;
                    }

                } else { // 活细胞
                    int cur_pos_live_num = live_num(i, j, board);
                    if (cur_pos_live_num < 2 || cur_pos_live_num > 3) {
                        ret[i][j] = 0;
                    } else {
                        ret[i][j] = 1;
                    }

                }

            }
        }

        board = ret;
    }
};

int main() {
    vector<vector<int>> board = {
            {0, 0}
    };

    Solution so;
    so.gameOfLife(board);

    for (auto cs: board) {
        for (auto c: cs) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}