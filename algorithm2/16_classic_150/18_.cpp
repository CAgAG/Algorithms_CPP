/*************************
 * @file   : 18_.cpp
 * @encode : UTF-8
 * @note   : 有效的数独 https://leetcode.cn/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/12 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> gen_check() {
        return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }

    bool check_rec(int start_x, int start_y, vector<vector<char>> &board, vector<int> &check_num) {
        for (int i = start_x; i < start_x + 3; ++i) {
            for (int j = start_y; j < start_y + 3; ++j) {
                if (board[i][j] != '.') {
                    if (check_num[board[i][j] - '0'] == 0) {
                        return false;
                    }
                    check_num[board[i][j] - '0'] = 0;
                }
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();

        vector<int> check_num;
        // 行
        for (int i = 0; i < m; ++i) {
            check_num = gen_check();
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    if (check_num[board[i][j] - '0'] == 0) {
                        return false;
                    }
                    check_num[board[i][j] - '0'] = 0;
                }
            }
        }

        // 列
        for (int i = 0; i < n; ++i) {
            check_num = gen_check();
            for (int j = 0; j < m; ++j) {
                if (board[j][i] != '.') {
                    if (check_num[board[j][i] - '0'] == 0) {
                        return false;
                    }
                    check_num[board[j][i] - '0'] = 0;
                }
            }
        }

        // 3x3
        int start_x = 0;
        int start_y = 0;

        while (1) {
            check_num = gen_check();
            int flag = check_rec(start_x, start_y, board, check_num);
            if (!flag) {
                return false;
            }

            start_x += 3;
            if (start_x >= m) {
                start_x = 0;
                start_y += 3;
                if (start_y >= n) {
                    break;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    Solution so;
    cout << so.isValidSudoku(board) << endl;

    return 0;
}