/*************************
 * @file   : 15_sudu.cpp
 * @encode : UTF-8
 * @note   : 解数独 https://leetcode.cn/problems/sudoku-solver/description/
 * @date   : 2024/3/26 19
 *************************/
/* 数独的解法需 遵循如下规则：
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 */

#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool check(int i, int j, char c, vector<vector<char>> &board) {
        int n = board.size();

        for (int k = 0; k < n; ++k) {
            if (board[i][k] == c) {
                return false;
            }
        }
        for (int k = 0; k < n; ++k) {
            if (board[k][j] == c) {
                return false;
            }
        }

        int range_row = (i / 3) * 3;
        int range_col = (j / 3) * 3;
        for (int k = range_row; k < range_row + 3; ++k) {
            for (int l = range_col; l < range_col + 3; ++l) {
                if (board[k][l] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtrace(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {  // 已填充数字
                    continue;
                }
                for (char c = '1'; c <= '9'; ++c) {
                    if (check(i, j, c, board)) {
                        board[i][j] = c;
                        if (backtrace(board) == true) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                // 9个数都无法填入
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board) {
        bool ret = backtrace(board);
        // cout << ret << endl;
        return;
    }
};

int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution so;
    so.solveSudoku(board);
    for (auto vecs: board) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}