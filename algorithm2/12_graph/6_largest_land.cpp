/*************************
 * @file   : 6_largest_land.cpp
 * @encode : UTF-8
 * @note   : 最大人工岛 https://leetcode.cn/problems/making-a-large-island/description/
 * @date   : 2024/4/28 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"

using namespace std;

class Solution {
public:
    vector<vector<int>> visited;
    int global_area_mark_i = 1;
    map<pair<int, int>, int> area_mark;
    vector<vector<int>> direction = {
            {-1, 0},
            {0,  -1},
            {1,  0},
            {0,  1}
    };

    int bfs(vector<vector<int>> &grid, int m, int n, int x, int y) {
        if (grid[x][y] == 0 || visited[x][y] != 0) {
            return 0;
        }

        vector<pair<int, int>> mark_p;
        int ret = 0;
        queue<pair<int, int>> que;
        que.push({x, y});
        while (!que.empty()) {
            ret++;
            pair<int, int> cur_p = que.front();
            que.pop();

            int cur_x = cur_p.first;
            int cur_y = cur_p.second;
            visited[cur_x][cur_y] = 1;
            mark_p.push_back(cur_p);

            for (int i = 0; i < direction.size(); ++i) {
                int may_x = cur_x + direction[i][0];
                int may_y = cur_y + direction[i][1];

                if (may_x < 0 || may_x >= m || may_y < 0 || may_y >= n) {
                    continue;
                }
                if (grid[may_x][may_y] == 0) {
                    continue;
                }
                if (visited[may_x][may_y] != 0) {
                    continue;
                }
                que.push({may_x, may_y});
                visited[may_x][may_y] = 1;
            }
        }

        // 将 标记转为 面积
        for (int i = 0; i < mark_p.size(); ++i) {
            int m_x = mark_p[i].first;
            int m_y = mark_p[i].second;
            visited[m_x][m_y] = ret;
            area_mark[mark_p[i]] = global_area_mark_i;
        }
        global_area_mark_i++;

        return ret;
    }


    int largestIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        int ret = 0;
        // 标记岛屿面积, 计算出的面积保存到 visited
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = max(ret, bfs(grid, m, n, i, j));
            }
        }

        // 尝试 将 0 ==> 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    // 已访问过的 区域编号
                    vector<int> visited_area;
                    int cur_x = i;
                    int cur_y = j;
                    int sum = 1;
                    for (int k = 0; k < direction.size(); ++k) {
                        int may_x = cur_x + direction[k][0];
                        int may_y = cur_y + direction[k][1];

                        if (may_x < 0 || may_x >= m || may_y < 0 || may_y >= n) {
                            continue;
                        }
                        // 已访问 区域编号
                        if (find(visited_area.begin(), visited_area.end(), area_mark[{may_x, may_y}]) !=
                            visited_area.end()) {
                            continue;
                        }
                        if (visited[may_x][may_y] == 0) {
                            continue;
                        }
                        sum += visited[may_x][may_y];
                        visited_area.push_back(area_mark[{may_x, may_y}]);
                    }
                    ret = max(ret, sum);
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> graph = {
            {0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 0, 0},
            {0, 1, 0, 0, 1, 0, 0},
            {1, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 0, 0},
            {0, 1, 1, 1, 1, 0, 0}
    };

    Solution so;
    cout << so.largestIsland(graph) << endl;

    return 0;
}


