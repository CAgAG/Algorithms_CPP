/*************************
 * @file   : 25_max_land.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/13 12
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"
#include "set"

using namespace std;


class Solution {
public:
    vector<vector<int>> visited;
    int c_i = 1;
    map<pair<int, int>, int> xy2c;
    vector<vector<int>> direction = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
    };


    void traver(vector<vector<int>> &grid, int s_x, int s_y) {
        if (grid[s_x][s_y] == 0 || visited[s_x][s_y] != 0) {
            return;
        }

        queue<pair<int, int>> que;
        que.push({s_x, s_y});
        vector<pair<int, int>> path;
        path.push_back({s_x, s_y});
        int sum = 1;

        while (!que.empty()) {
            pair<int, int> ele = que.front();
            que.pop();
            int cur_x = ele.first;
            int cur_y = ele.second;

            visited[cur_x][cur_y] = 1;
            for (int i = 0; i < direction.size(); ++i) {
                int may_x = cur_x + direction[i][0];
                int may_y = cur_y + direction[i][1];

                // 越界
                if (may_x < 0 || may_y < 0 || may_x >= grid.size() || may_y >= grid[may_x].size()) {
                    continue;
                }
                // 出海
                if (grid[may_x][may_y] == 0) {
                    continue;
                }
                // 来过
                if (visited[may_x][may_y] != 0) {
                    continue;
                }

                que.push({may_x, may_y});
                path.push_back({may_x, may_y});
                visited[may_x][may_y] = 1;
                sum++;
            }
        }

        // 更新面积
        for (int i = 0; i < path.size(); ++i) {
            int cur_x = path[i].first;
            int cur_y = path[i].second;
            visited[cur_x][cur_y] = sum;

            xy2c[{cur_x, cur_y}] = c_i;
        }
        c_i++;

    }


    int largestIsland(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        visited = vector<vector<int>>(m, vector<int>(n, 0));
        xy2c = map<pair<int, int>, int>();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                traver(grid, i, j);
            }
        }

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int cur_ret = 1;
                    set<int> visited_c_i;

                    for (int k = 0; k < direction.size(); ++k) {
                        int may_x = i + direction[k][0];
                        int may_y = j + direction[k][1];
                        // 越界
                        if (may_x < 0 || may_y < 0 || may_x >= grid.size() || may_y >= grid[may_x].size()) {
                            continue;
                        }
                        int cur_c_i = xy2c[{may_x, may_y}];
                        if (visited_c_i.find(cur_c_i) != visited_c_i.end()) {
                            continue;
                        }

                        visited_c_i.insert(cur_c_i);
                        cur_ret += visited[may_x][may_y];
                    }
                    ret = max(ret, cur_ret);
                } else {
                    int cur_ret = 0;
                    set<int> visited_c_i;

                    for (int k = 0; k < direction.size(); ++k) {
                        int may_x = i + direction[k][0];
                        int may_y = j + direction[k][1];
                        // 越界
                        if (may_x < 0 || may_y < 0 || may_x >= grid.size() || may_y >= grid[may_x].size()) {
                            continue;
                        }
                        int cur_c_i = xy2c[{may_x, may_y}];
                        if (visited_c_i.find(cur_c_i) != visited_c_i.end()) {
                            continue;
                        }

                        visited_c_i.insert(cur_c_i);
                        cur_ret += visited[may_x][may_y];
                    }
                    ret = max(ret, max(cur_ret, 1));
                }

            }
        }
        return ret;
    }
};


int main() {
    vector<vector<int>> grid = {
            {0, 0},
            {1, 0}
    };

    Solution so;
    cout << so.largestIsland(grid) << endl;

    return 0;
}