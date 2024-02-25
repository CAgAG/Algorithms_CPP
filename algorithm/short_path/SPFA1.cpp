/*************************
 * @file   : SPFA.cpp
 * @encode : UTF-8
 * @note   : SPFA（Shortest Path Faster Algorithm）是一种用于解决带权有向图中最短路径问题的算法，它是Bellman-Ford算法的一种优化
 *           可以处理 负权, 但不能有 负环
 * @date   : 2024/2/24 14
 *************************/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 100; // 最大节点数
const int INF = INT_MAX; // 无穷大，表示不可达

int n; // 节点数
int dist[MAXN]; // dist[i]表示从源点到节点i的最短距离
vector<pair<int, int>> adj[MAXN]; // 邻接表存图
bool inQueue[MAXN]; // 标记节点是否在队列中, 相当于 vis 数组, 但代表的含义不同

void SPFA(int s) {
    fill(dist, dist + n + 1, INF); // 初始化所有距离为无穷大
    dist[s] = 0; // 源点到自身的距离为0
    queue<int> q;
    q.push(s); // 将源点加入队列
    inQueue[s] = true; // 标记源点在队列中

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false; // 节点u出队

        for (const auto &edge: adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; // 更新最短距离
                if (!inQueue[v]) {
                    inQueue[v] = true; // 标记节点v在队列中
                    q.push(v); // 将节点v加入队列
                }
            }
        }
    }
}

int main() {
    n = 6; // 图的节点数

    // 手动初始化一个有代表性的图
    // 添加边：(u, v, w)，表示从节点u到节点v有一条权值为w的边
    adj[0].push_back({1, 3});
    adj[0].push_back({2, 5});
    adj[1].push_back({3, 2});
    adj[1].push_back({4, 4});
    adj[2].push_back({3, 1});
    adj[3].push_back({5, 2});
    adj[4].push_back({5, 1});

    int s = 0; // 源点
    SPFA(s); // 从源点开始计算最短路径

    // 输出从源点到所有节点的最短距离
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "IMPOSSIBLE" << endl; // 不可达
        } else {
            cout << "Distance from " << s << " to " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}