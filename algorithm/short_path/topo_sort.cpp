/*************************
 * @file   : topo_sort.cpp
 * @encode : UTF-8
 * @note   : 拓扑排序实现
 * @date   : 2024/2/24 13
 *************************/

#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[1000]; // 邻接表存储图
int indegree[1000]; // 记录每个节点的入度

void topoSort(int node_size) {
    queue<int> q;

    // 将所有入度为0的节点加入队列
    for (int i = 0; i < node_size; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 当队列不为空时，取出队首元素并打印，然后将其所有邻接点的入度减1
    // 如果邻接点的入度变为0，则将其加入队列
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (auto v: adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int node_size = 6; // 顶点数

    // 添加边，格式为：u v，表示从u到v的一条有向边
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // 计算每个节点的入度
    for (int i = 0; i < node_size; i++) {
        for (auto j: adj[i]) {
            indegree[j]++;
        }
    }

    // 拓扑排序
    topoSort(node_size);

    return 0;
}