/*************************
 * @file   : 17_graph_set.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/11 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> parent;

    void init(int n) {
        parent = vector<int>(n + 1, 0);
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


    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> ret;
        init(n);

        for (vector<int> ed: edges) {
            int u = ed[0];
            int v = ed[1];
            if (is_same(u, v)) {
                ret = ed;
            }
            join(u, v);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> edges = {
            {1, 2},
            {1, 3},
            {2, 3}
    };

    Solution so;
    for (auto s: so.findRedundantConnection(edges)) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}