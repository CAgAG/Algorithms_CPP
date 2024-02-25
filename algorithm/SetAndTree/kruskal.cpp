/*************************
 * @file   : kruskal.cpp
 * @encode : UTF-8
 * @note   : Kruskal算法是一种用于找到加权无向图的最小生成树的贪心算法。它按照边的权重从小到大排序，然后依次选择边，
 *           但选择的边不能与已选择的边构成环。并查集在这里用于高效地检测环。
 * @date   : 2024/2/25 13
 *************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int u, v, weight;

    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

vector<pair<int, int>> path;

int kruskal(int n, vector<Edge> &edges) {
    UnionFind uf(n);
    sort(edges.begin(), edges.end());

    int totalWeight = 0;
    for (const Edge &edge: edges) {
        if (!uf.connected(edge.u, edge.v)) {  // 不会形成 环
            uf.unite(edge.u, edge.v);
            path.push_back({edge.u, edge.v});
            totalWeight += edge.weight;
        }
    }

    return totalWeight;
}

int main() {
    // 示例图：  
    // 0 -- 10* --  3
    // |      --    |
    // 6*   -- 5*   4*
    // |  --        |
    // 1 -- 15* -- 2
    int n = 4; // 节点的数量  
    vector<Edge> edges = {
            {0, 1, 6},
            {0, 3, 10},
            {1, 3, 5},
            {1, 2, 15},
            {2, 3, 4}
    };

    int minTreeWeight = kruskal(n, edges);
    cout << "The weight of the minimum spanning tree is: " << minTreeWeight << endl;

    for (auto ele: path) {
        cout << "{" << ele.first << "," << ele.second << "} ";
    }
    cout <<endl;
    return 0;
}

/* 排序边：Kruskal算法的第一步是对所有边按照权重进行排序。如果图中有E条边，那么排序的时间复杂度通常是O(E log E)，这取决于所使用的排序算法。
 * 在实际应用中，快速排序、归并排序等算法常被用于此目的。
 */