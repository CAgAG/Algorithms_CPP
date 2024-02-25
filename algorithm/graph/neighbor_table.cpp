/*************************
 * @file   : neighbor_table.cpp
 * @encode : UTF-8
 * @note   : 邻接表
 * @date   : 2024/2/23 22
 *************************/

#include "cstring"
#include "vector"
#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

vector<int> table[10];
vector<int> path;
vector<pair<int, int>> table2[10];  // 带权图

int vis[11];
int vis2[11];
int dis[11];  // 计算点与其他点之间的最小距离
queue<int> que;

void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void dfs(int cur_node) {
    path.push_back(cur_node);
    vis[cur_node] = 1;
    for (auto to: table[cur_node]) {
        if (!vis[to]) {
            dfs(to);
            print_vector(path);
            path.pop_back();
            vis[to] = 0;
        }
    }
}

void bfs(int root_node) {
    que.push(root_node);
    vis2[root_node] = 1;
    dis[root_node] = 0;

    while (!que.empty()) {
        int cur_node = que.front();
        que.pop();
        cout << cur_node << " ";

        for (auto to: table[cur_node]) {
            if (!vis2[to]) {
                dis[to] = min(dis[to], dis[cur_node] + 1);
                que.push(to);
                vis2[to] = 1;
            }
        }
    }
}

int main() {

    // 0 节点与 1, 2节点相连
    table[0].push_back(1);
    table[0].push_back(2);

    // 0 节点与 1, 2节点相连, 边权分别是 10 和 20
    table2[0].push_back({1, 10});
    table2[0].push_back({2, 20});

    // =============================
    table[1].push_back(0);
    table[2].push_back(0);
    // 节点1到节点2
    table[1].push_back(2);
    table[2].push_back(1);
    // 节点2到节点3
    table[2].push_back(3);
    table[3].push_back(2);
    // 节点3到节点4
    table[3].push_back(4);
    table[4].push_back(3);
    // 节点4到节点5
    table[4].push_back(5);
    table[5].push_back(4);
    // 节点5到节点6
    table[5].push_back(6);
    table[6].push_back(5);
    // 节点6到节点7
    table[6].push_back(7);
    table[7].push_back(6);
    // 节点7到节点8
    table[7].push_back(8);
    table[8].push_back(7);
    // 节点8到节点9
    table[8].push_back(9);
    table[9].push_back(8);

    // =============================
    dfs(0);

    cout << "============================" << endl;
    memset(dis, 0x3f, sizeof(dis));
    bfs(0);

    cout << endl << "============================" << endl;
    for (int i = 0; i < 11; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}