/*************************
 * @file   : 33_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/25 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {
            {0,  1},
            {1,  0},
            {-1, 0},
            {0,  -1}
    };
    vector<vector<bool>> used;
    int m = 0;
    int n = 0;

    bool traver(vector<vector<char>> &board, string word, int next_word_index, int cur_x, int cur_y) {
        if (next_word_index == word.size()) {
            return true;
        }

        for (int i = 0; i < direction.size(); ++i) {
            int may_x = cur_x + direction[i][0];
            int may_y = cur_y + direction[i][1];

            if (may_x < 0 || may_y < 0 || may_x >= m || may_y >= n) {
                continue;
            }
            if (used[may_x][may_y]) {
                continue;
            }

            if (board[may_x][may_y] == word[next_word_index]) {
                used[may_x][may_y] = true;
                if (traver(board, word, next_word_index + 1, may_x, may_y)) {
                    return true;
                }
                used[may_x][may_y] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                used = vector<vector<bool>>(m, vector<bool>(n, false));
                used[i][j] = true;
                if (board[i][j] == word[0] && traver(board, word, 1, i, j)) {
                    return true;
                }

            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    string s = "SEE";

    Solution so;
    cout << so.exist(board, s) << endl;

    return 0;
}