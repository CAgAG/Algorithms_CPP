/*************************
 * @file   : 11_land_edge.cpp
 * @encode : UTF-8
 * @note   : 岛屿的周长 https://leetcode.cn/problems/island-perimeter/description/
 * @date   : 2024/4/28 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1}
    };

    int islandPerimeter(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int cur_x = i;
                    int cur_y = j;
                    for (int k = 0; k < direction.size(); ++k) {
                        int may_x = cur_x + direction[k][0];
                        int may_y = cur_y + direction[k][1];
                        // 在边界上
                        if (may_x < 0 || may_x >= m || may_y < 0 || may_y >= n) {
                            ret++;
                            continue;
                        }
                        // 接近水
                        if (grid[may_x][may_y] == 0) {
                            ret++;
                            continue;
                        }
                    }

                }
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> graph = {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}
    };

    Solution so;
    cout << so.islandPerimeter(graph) << endl;

    return 0;
}