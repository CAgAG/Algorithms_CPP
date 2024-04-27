/*************************
 * @file   : 14_N_queen.cpp
 * @encode : UTF-8
 * @note   : N皇后 https://leetcode.cn/problems/n-queens/description/
 * @date   : 2024/3/26 14
 *************************/

/* 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。 */
/* n*n 的棋盘放 n格皇后， 也即每行都要放一个皇后 */

#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "unordered_map"

using namespace std;

class Solution {
private:
    vector<vector<string>> ret;

public:
    // 检查已经遍历过的地方是否符合要求
    bool isValid(int row, int col, vector<string> &chessboard, int n) {
        /* 可以不对同行进行检查
         * 因为在单层搜索的过程中，每一层递归，只会选for循环（也就是同一行）里的一个元素。 */
        for (int i = 0; i < col; ++i) {
            if (chessboard[row][i] == 'Q') {
                return false;
            }
        }

        // 检查列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后. 根据i, j来使用矢量的 三角形法则来判断
        // 向左上扫描
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        // 向右上扫描
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }


    // n 为输入的棋盘大小
    // row 是当前递归到棋盘的第几行了
    void backtrace(int n, int row, vector<string> &chessboard) {
        if (row >= n) {
            ret.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
                chessboard[row][col] = 'Q'; // 放置皇后
                backtrace(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯，撤销皇后
            }
        }
    }
    /* 给出了棋盘的宽度就是for循环的长度，递归的深度就是棋盘的高度，这样就可以套进回溯法的模板里了  */

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtrace(n, 0, chessboard);
        return ret;
    }
};

int main() {
    int n = 4;

    Solution so;
    auto result = so.solveNQueens(n);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}