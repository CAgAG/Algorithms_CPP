/*************************
 * @file   : 2_remove_edge.cpp 并查集
 * @encode : UTF-8
 * @note   : 冗余连接II https://leetcode.cn/problems/redundant-connection-ii/description/
 * @date   : 2024/4/27 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/* 在本问题中，有根树指满足以下条件的 有向 图。
 * 该树只有一个根节点，所有其他节点都是该根节点的后继。
 * 该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 */
// 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树
// 题目中的图【原本是是一棵树】，只不过在不增加节点的情况下【多加了一条边】

class Solution {
public:
    int n;
    vector<int> parent;

    void init() {
        // 注意这里是 小于等于，因为节点是 1..n，不是0..n-1
        for (int i = 0; i <= n; ++i) {
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

    // =========================
    // 【没有入度为2的点】，那么图中一定【出现了有向环】（注意这里强调是有向环！）
    /* 前两种入度为2的情况，
     * 一定是删除指向入度为2的节点的两条边其中的一条，如果删了一条，判断这个图是一个树，那么这条边就是答案
     * 情况三，明确没有入度为2的情况，那么一定有向环，找到构成环的边就是要删除的边
     */
    // isTreeAfterRemoveEdge() 判断删一个边之后是不是树了
    // getRemoveEdge() 确定图中一定有了有向环，那么要找到需要删除的那条边

    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>> &edges, int deleteEdge) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge) continue;
            if (is_same(edges[i][0], edges[i][1])) { // 构成有向环了，一定不是树
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    // 在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>> &edges) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) { // 遍历所有的边
            if (is_same(edges[i][0], edges[i][1])) { // 构成有向环了，就是要删除的边
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    // =========================
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        n = edges.size();
        parent = vector<int>(n + 1, 0);
        // 统计节点入度
        vector<int> inDegree(n + 1, 0); // 记录节点入度
        for (int i = 0; i < n; i++) {
            inDegree[edges[i][1]]++; // 统计入度
        }
        // 统计入度为2的边
        vector<int> in_2_Degree; // 记录入度为2的边（如果有的话就两条边）
        // 找入度为2的节点所对应的边，注意要倒序，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--) {  // 从后向前遍历
            if (inDegree[edges[i][1]] == 2) {
                in_2_Degree.push_back(i);
            }
        }

        // 处理图中情况1 和 情况2
        // 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
        if (in_2_Degree.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, in_2_Degree[0])) {
                return edges[in_2_Degree[0]];
            } else {
                return edges[in_2_Degree[1]];
            }
        }
        // 处理图中情况3
        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
        return getRemoveEdge(edges);

    }
};

int main() {
    vector<vector<int>> edge = {
            {1, 2},
            {1, 3},
            {2, 3}
    };

    Solution so;
    for (int it: so.findRedundantDirectedConnection(edge)) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}