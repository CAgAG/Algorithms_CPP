/*************************
 * @file   : 8_edge_land_count.cpp
 * @encode : UTF-8
 * @note   : 飞地的数量 https://leetcode.cn/problems/number-of-enclaves/description/
 * @date   : 2024/4/28 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> direction = {
            {-1, 0},
            {0,  -1},
            {1,  0},
            {0,  1}
    };
    int per_count = 1;
    bool is_out = false;

    // 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格
    void dfs(vector<vector<int>> &grid, int m, int n, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < direction.size(); ++i) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            // 溢出边界
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                is_out = true;
                continue;
            }
            if (grid[next_x][next_y] == 0) {
                continue;
            }
            if (visited[next_x][next_y]) {
                continue;
            }
            visited[next_x][next_y] = true;
            per_count++;
            dfs(grid, m, n, next_x, next_y);
        }
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    per_count = 1;
                    is_out = false;
                    dfs(grid, m, n, i, j);
                    if (!is_out) {
                        ret += per_count;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> graph = {
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
    };

    Solution so;

    cout << so.numEnclaves(graph) << endl;

    return 0;
}