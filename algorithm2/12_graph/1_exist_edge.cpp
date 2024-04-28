/*************************
 * @file   : 1_exist_edge.cpp 并查集
 * @encode : UTF-8
 * @note   : 寻找图中是否存在路径 https://leetcode.cn/problems/find-if-path-exists-in-graph/description/
 * @date   : 2024/4/27 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    vector<int> parent;

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }

    bool is_same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        parent[v] = u;
    }


    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        parent = vector(n + 1, 0);
        init(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            join(u, v);
        }

        return is_same(source, destination);
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edge = {
            {0, 1},
            {1, 2},
            {2, 0}
    };
    int s = 0;
    int t = 2;

    Solution so;
    cout << so.validPath(n, edge, s, t) << endl;
    return 0;
}