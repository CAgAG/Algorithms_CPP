/*************************
 * @file   : 4_land_count.cpp dfs解决
 * @encode : UTF-8
 * @note   : 岛屿数量 https://leetcode.cn/problems/number-of-islands/description/
 * @date   : 2024/4/27 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

// 本题思路，是用遇到一个没有遍历过的节点陆地，计数器就加一，然后把该节点陆地所能遍历到的陆地都标记上。
// 在遇到标记过的陆地节点和海洋节点的时候直接跳过。 这样计数器就是最终岛屿的数量。

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> direction = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1}
    };

    // 是否进行了 dfs 至少一个节点
    bool dfs(vector<vector<char>> &grid, int x, int y) {
        // 坐标合法
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }
        // 只遍历未遍历过的陆地
        if (grid[x][y] == '0' || visited[x][y]) {
            return false;
        }

        visited[x][y] = true;
        for (int i = 0; i < direction.size(); ++i) {
            x += direction[i][0];
            y += direction[i][1];
            dfs(grid, x, y);
            x -= direction[i][0];
            y -= direction[i][1];
        }
        return true;
    }

    int numIslands(vector<vector<char>> &grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        int ret = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (dfs(grid, i, j)) {
                    ret++;
                }
            }
        }

        return ret;
    }
};

int main() {
    vector<vector<char>> graph = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };

    Solution so;

    cout << so.numIslands(graph) << endl;

    return 0;
}
