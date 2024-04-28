/*************************
 * @file   : 10_key_and_room.cpp
 * @encode : UTF-8
 * @note   : 钥匙和房间 https://leetcode.cn/problems/keys-and-rooms/description/
 * @date   : 2024/4/28 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// 代码中可以看到dfs函数下面并没有回溯的操作。
// 此时就要在思考本题的要求了，本题是需要判断 0节点是否能到所有节点，那么我们就没有必要回溯去撤销操作了，只要遍历过的节点一律都标记上。

// 那什么时候需要回溯操作呢？
// 当我们需要搜索一条可行路径的时候，就需要回溯操作了，因为没有回溯，就没法“调头”

class Solution {
public:
    vector<bool> visited;

    void dfs(vector<vector<int>> &rooms, int cur_room) {
        if (visited[cur_room]) {
            return;
        }

        visited[cur_room] = true;
        for (int i = 0; i < rooms[cur_room].size(); ++i) {
            int cur_key = rooms[cur_room][i];
            dfs(rooms, cur_key);
        }
    }


    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();

        visited = vector<bool>(n, false);
        dfs(rooms, 0);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {
            {1},
            {2},
            {3},
            {}
    };

    Solution so;
    cout << so.canVisitAllRooms(graph) << endl;

    return 0;
}