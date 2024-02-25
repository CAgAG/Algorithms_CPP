/*************************
 * @file   : union_find.cpp
 * @encode : UTF-8
 * @note   : 并查集实现
 * @date   : 2024/2/25 12
 *************************/

#include<iostream>
#include<vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;  // 用于查找每个元素的父节点是哪个节点(头目)

public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // 自己是自己的头目-对应强盗问题
        }
    }

    // 递归实现
    int find(int x) {
        /* find(x): 找到元素x的根节点（即代表元素）. 在查找过程中，我们进行了路径压缩，使得后续的查找更为迅速。*/
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩，使得后续的查找更为迅速
        }
        return parent[x];
    }

    // 非递归-循环实现
    int find_loop(int x) {
        int root = x;
        // 找到根节点, 即代表头目
        while (parent[root] != root) {
            root = parent[root];
        }

        // 路径压缩：将x到根节点路径上的所有节点的父节点直接设置为根节点, 这一步不是必须的
        int i = x;
        while (i != root) {
            int temp = parent[i];
            parent[i] = root;
            i = temp;
        }
        return root;
    }

    void unite(int x, int y) {
        /* unite(x, y): 将元素x和元素y所在的两个集合合并为一个集合。
         * 具体实现时，我们分别找到x和y的根节点，然后将x的根节点的父节点设置为y的根节点
         * （注意这里也可以将y的根节点的父节点设置为x的根节点，效果是一样的）。 */
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {  // 这个判断可以不要
            parent[rootX] = rootY; // 将x的根节点连接到y的根节点上
        }
    }

    bool connected(int x, int y) {
        /* connected(x, y): 判断元素x和元素y是否在同一个集合中。具体实现时，我们只需要比较x和y的根节点是否相同即可。 */
        return find(x) == find(y);
    }
};

int main() {
    UnionFind uf(5);
    uf.unite(0, 1);
    uf.unite(1, 2);
    cout << uf.connected(0, 2) << endl;  // 输出1，表示0和2是连通的
    cout << uf.connected(0, 3) << endl;  // 输出0，表示0和3不是连通的
    return 0;
}