/*************************
 * @file   : 29_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/24 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    vector<vector<bool>> visited;

    int orangesRotting(vector<vector<int>> &grid) {
        int ret = 0;

        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        queue<pair<int, int>> que;

        int count_1 = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur_p = grid[i][j];
                if (cur_p == 2) {
                    que.push({i, j});
                } else if (cur_p == 1) {
                    count_1++;
                }
            }
        }

        while (!que.empty()) {
            int cur_que_length = que.size();
            for (int g = 0; g < cur_que_length; ++g) {
                int i = que.front().first;
                int j = que.front().second;
                visited[i][j] = true;
                que.pop();
                for (int k = 0; k < direction.size(); ++k) {
                    int may_x = i + direction[k][0];
                    int may_y = j + direction[k][1];

                    if (may_x >= m || may_y >= n || may_x < 0 || may_y < 0) {
                        continue;
                    }
                    if (visited[may_x][may_y]) {
                        continue;
                    }
                    if (grid[may_x][may_y] == 1) {
                        count_1--;
                        grid[may_x][may_y] = 2;
                        que.push({may_x, may_y});
                    }

                }
            }
            ret++;
        }


        if (count_1 > 0) {
            return -1;
        }
        return max(ret - 1, 0);
    }
};

int main() {
    vector<vector<int>> nums = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
    };

    Solution so;
    cout << so.orangesRotting(nums) << endl;

    return 0;
}