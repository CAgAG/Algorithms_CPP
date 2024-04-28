/*************************
 * @file   : 5_max_land_area.cpp bfs
 * @encode : UTF-8
 * @note   : 岛屿的最大面积 https://leetcode.cn/problems/max-area-of-island/description/
 * @date   : 2024/4/27 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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

    int bfs(vector<vector<int>> &grid, int x, int y, int m, int n) {
        if (grid[x][y] == 0 || visited[x][y]) {
            return 0;
        }

        int ret = 0;
        queue<pair<int, int>> que;
        que.push({x, y});
        while (!que.empty()) {
            ret++;
            pair<int, int> cur_p = que.front();
            que.pop();
            int cur_x = cur_p.first;
            int cur_y = cur_p.second;
            // 别忘了标记 当前节点
            visited[cur_x][cur_y] = true;

            for (int i = 0; i < direction.size(); ++i) {
                // 下一个可能的坐标
                int may_x = cur_x + direction[i][0];
                int may_y = cur_y + direction[i][1];
                // 不合法坐标
                if (may_x < 0 || may_x >= m || may_y < 0 || may_y >= n) {
                    continue;
                }
                // 不是陆地
                if (grid[may_x][may_y] == 0) {
                    continue;
                }
                // 已经遍历过的陆地
                if (visited[may_x][may_y]) {
                    continue;
                }
                visited[may_x][may_y] = true;
                que.push({may_x, may_y});
            }
        }
        return ret;
    }


    int maxAreaOfIsland(vector<vector<int>> &grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int m = grid.size(), n = grid[0].size();

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = max(ret, bfs(grid, i, j, m, n));
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> graph = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                 {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                 {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    Solution so;
    cout << so.maxAreaOfIsland(graph) << endl;

    return 0;
}
