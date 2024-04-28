/*************************
 * @file   : 9_water_go.cpp
 * @encode : UTF-8
 * @note   : 太平洋大西洋水流问题 https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
 * @date   : 2024/4/28 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

// 那么我们可以 反过来想，从太平洋边上的节点 逆流而上，将遍历过的节点都标记上。
// 从大西洋的边上节点 逆流而长，将遍历过的节点也标记上。
// 然后两方都标记过的节点就是既可以流太平洋也可以流大西洋的节点。

class Solution {
public:
    vector<vector<int>> direction = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1}
    };
    vector<vector<vector<bool>>> visited;

    void dfs(vector<vector<int>> &grid, int m, int n, int x, int y, int mark_index) {
        visited[x][y][mark_index] = true;
        for (int i = 0; i < direction.size(); ++i) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];

            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                continue;
            }
            // 往大的数走
            if (grid[x][y] > grid[next_x][next_y]) {
                continue;
            }
            if (visited[next_x][next_y][mark_index]) {
                continue;
            }
            visited[next_x][next_y][mark_index] = true;
            dfs(grid, m, n, next_x, next_y, mark_index);
        }

    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        visited = vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(2, false)));

        // 第一行，第一列
        for (int j = 0; j < n; ++j) {
            int cur_x = 0;
            int cur_y = j;
            dfs(heights, m, n, cur_x, cur_y, 0);
        }
        for (int i = 0; i < m; ++i) {
            int cur_x = i;
            int cur_y = 0;
            dfs(heights, m, n, cur_x, cur_y, 0);
        }

        // 最后一行，最后一列
        for (int j = 0; j < n; ++j) {
            int cur_x = m - 1;
            int cur_y = j;
            dfs(heights, m, n, cur_x, cur_y, 1);
        }
        for (int i = 0; i < m; ++i) {
            int cur_x = i;
            int cur_y = n - 1;
            dfs(heights, m, n, cur_x, cur_y, 1);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j][0] && visited[i][j][1]) {
                    ret.push_back({i, j});
                }

            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> graph = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
    };

    Solution so;

    for (auto its: so.pacificAtlantic(graph)) {
        for (auto it: its) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}