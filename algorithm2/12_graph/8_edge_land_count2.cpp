/*************************
 * @file   : 8_edge_land_count.cpp
 * @encode : UTF-8
 * @note   : 被围绕的区域 https://leetcode.cn/problems/surrounded-regions/description/
 * @date   : 2024/4/28 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

// 【飞地的数量】正好反过来了，飞地的数量是求 地图中间的空格数，而本题是要把地图中间的'O'都改成'X'

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> direction = {
            {-1, 0},
            {0,  -1},
            {1,  0},
            {0,  1}
    };
    bool is_out = false;
    vector<vector<int>> path;

    // 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格
    void dfs(vector<vector<char>> &grid, int m, int n, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < direction.size(); ++i) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            // 溢出边界
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                is_out = true;
                continue;
            }
            if (grid[next_x][next_y] == 'X') {
                continue;
            }
            if (visited[next_x][next_y]) {
                continue;
            }
            visited[next_x][next_y] = true;
            path.push_back({next_x, next_y});
            dfs(grid, m, n, next_x, next_y);
        }
    }

    void fill(vector<vector<char>> &grid, vector<vector<int>> points) {
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            if (grid[x][y] == 'O') {
                grid[x][y] = 'X';
            }
        }
    }

    void solve(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'O' && !visited[i][j]) {
                    is_out = false;
                    path = {{i, j}};
                    dfs(grid, m, n, i, j);
                    if (!is_out) {
                        fill(grid, path);
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> graph = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };

    Solution so;

    so.solve(graph);

    for (auto its: graph) {
        for (auto it: its) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}