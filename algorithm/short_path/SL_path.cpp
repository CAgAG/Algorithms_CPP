/*************************
 * @file   : SL_path.cpp
 * @encode : UTF-8
 * @note   : 动态规划实际上是在一张有向无环图上进行拓扑排序的过程
 * @date   : 2024/2/24 13
 *************************/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

vector<Edge> G[MAXN];
int inDegree[MAXN];
int dist[MAXN]; // dist[i]表示从起点到节点i的最短距离

void addEdge(int u, int v, int w) {
    G[u].push_back({v, w});
    inDegree[v]++;
}

void topologicalSort(int n, int source) {
    queue<int> q;
    fill(dist, dist + n, INF); // 初始化所有距离为无穷大
    dist[source] = 0; // 源节点到自身的距离是0

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : G[u]) {
            int v = e.to;
            int w = e.weight;
            inDegree[v]--;

            // 更新最短距离
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                /* 算法(SPFA)描述：起点开始，周围点若距离有更新（变短)，就更新距离
                 * 优化点:
                 * 若被更新点不在队列望，就把被更新点入列；(注意此处逻辑）*/
                dist[v] = dist[u] + w;
            }

            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 5, m = 6;
    int source = 0; // 假设节点0是源节点

    addEdge(0, 1, 2);
    addEdge(0, 2, 3);
    addEdge(1, 3, 4);
    addEdge(1, 4, 5);
    addEdge(2, 3, 6);
    addEdge(3, 4, 7);

    topologicalSort(n, source);

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": shortest distance = " << (dist[i] == INF ? -1 : dist[i]) << endl; // 如果距离是无穷大，则输出-1
    }

    return 0;
}
