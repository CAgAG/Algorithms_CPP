/*************************
 * @file   : FW.cpp
 * @encode : UTF-8
 * @note   : 使用Floyd-Warshall算法计算所有节点对之间的最短路径
 * @date   : 2024/2/24 16
 *************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(const vector<vector<int>> &graph, vector<vector<int>> &dist) {
    int n = graph.size();

    // 初始化距离矩阵，对角线上的值为0，表示节点到自身的距离为0
    // 其他值初始化为INF，表示当前还不知道最短路径
    // 其实就是初始化为 邻接矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = graph[i][j];
        }
        dist[i][i] = 0;
    }

    // Floyd-Warshall算法的核心部分
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 如果通过节点k的路径更短，则更新dist[i][j]
                // 其实相当于 i与 j节点之间有 k节点
                // 能否通过在 i节点和 j节点之间添加 k节点的方式, 来使得路径更短; 注意此处 k是有可能等于 i和 j的
                if (dist[i][k] != INF && dist[k][j] != INF  // i节点和 j节点之间是否存在 k节点
                    && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n = 4; // 节点数
    vector<vector<int>> graph = {
            {0,   5,   INF, 10},
            {INF, 0,   3,   INF},
            {INF, INF, 0,   1},
            {INF, INF, INF, 0}
    }; // 直接初始化的有代表性图的邻接矩阵

    vector<vector<int>> dist(n, vector<int>(n, INF)); // 存储最短路径的矩阵, 两个位置 i和j 的值分别表示从节点 i到节点 j的最短路径值

    floydWarshall(graph, dist); // 执行Floyd-Warshall算法

    // 输出所有节点对之间的最短路径
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF "; // 如果不可达，则输出INF
            } else {
                cout << dist[i][j] << " "; // 输出最短路径的长度
            }
        }
        cout << endl;
    }

    return 0;
}