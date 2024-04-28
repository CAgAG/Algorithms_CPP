/*************************
 * @file   : 2_remove_edge.cpp 并查集
 * @encode : UTF-8
 * @note   : 寻找图中是否存在路径 https://leetcode.cn/problems/redundant-connection/description/
 * @date   : 2024/4/27 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int n;
    vector<int> parent;

    void init() {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        parent[v] = u;
    }

    bool is_same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }


    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        n = edges.size();
        parent = vector(n + 1, 0);

        init();
        vector<int> ret;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!is_same(u, v)) {  // 不连通就加入
                join(u, v);
            } else { // 不影响目前节点的连通性
                ret = edges[i];  // 记录最后一个
                join(u, v);
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> edge = {
            {1, 2},
            {1, 3},
            {2, 3}
    };

    Solution so;
    for (int it: so.findRedundantConnection(edge)) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}