/*************************
 * @file   : Dijkstra2.cpp
 * @encode : UTF-8
 * @note   : 不能处理 负权
 * @date   : 2024/2/24 15
 *************************/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int INF = INT_MAX;

void dijkstra(const vector<vector<pair<int, int>>> &graph, int src, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // pair优先对比的是第一个数

    fill(dist.begin(), dist.end(), INF); // 初始化所有距离为无穷大
    dist[src] = 0; // 源点到自身的距离为0
    pq.push({0, src}); // 将源点加入优先队列, 分别表示距离和节点

    while (!pq.empty()) {
        int cur_node = pq.top().second; // 取出当前距离最短的节点
        pq.pop();

        for (const auto &edge: graph[cur_node]) {
            int to_node = edge.first; // 边的终点
            int weight = edge.second; // 边的权重

            if (dist[to_node] > dist[cur_node] + weight) {
                dist[to_node] = dist[cur_node] + weight; // 更新最短距离
                pq.push({dist[to_node], to_node}); // 将节点v加入优先队列
            }
        }
    }
}

int main() {
    int n = 6; // 节点数
    vector<vector<pair<int, int>>> graph(n); // 邻接表存图

    // 直接初始化一个有代表性的图
    graph[0].push_back({1, 4});  // 节点和边权
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[1].push_back({2, 5});
    graph[2].push_back({3, 1});
    graph[3].push_back({4, 3});
    graph[4].push_back({5, 2});
    graph[5].push_back({3, 6});

    int src = 0; // 源点
    vector<int> dist(n, 0); // 存储源点到各个节点的最短距离 --> 函数里会初始化为无穷大, 此处仅仅只是定义

    dijkstra(graph, src, dist); // 执行Dijkstra算法

    // 输出结果
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is not reachable from node " << src << endl;
        } else {
            cout << "Shortest distance from node " << src << " to node " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}