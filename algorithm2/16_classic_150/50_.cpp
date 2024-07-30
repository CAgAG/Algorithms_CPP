/*************************
 * @file   : 50_.cpp
 * @encode : UTF-8
 * @note   : 建立四叉树 https://leetcode.cn/problems/construct-quad-tree/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/24 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/* 四叉树数据结构中，每个内部节点有四个子节点。此外，每个节点都有两个属性 */

class Node {
public:
    // val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False
    bool val;
    // 当这个节点是一个叶子结点时为 True
    bool isLeaf;
    // 四个节点
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/*
二维区域构建四叉树：
1. 如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
2. 如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
3. 使用适当的子网格递归每个子节点。
 */

class Solution {
public:
    int m, n;

    // 全闭区间
    int check_rec(vector<vector<int>> &grid, int top_limit, int right_limit, int bottom_limit, int left_limit) {
        int first_num = grid[top_limit][left_limit];
        for (int i = top_limit; i <= bottom_limit; ++i) {
            for (int j = left_limit; j <= right_limit; ++j) {
                if (grid[i][j] != first_num) {
                    return -1;
                }
            }
        }
        return first_num;
    }

    Node *build(vector<vector<int>> &grid, int top_limit, int right_limit, int bottom_limit, int left_limit) {
        if (top_limit < 0 || right_limit > n || bottom_limit > m || left_limit < 0) {
            return nullptr;
        }

        Node *node = new Node();
        int check_num = check_rec(grid, top_limit, right_limit, bottom_limit, left_limit);
        if (check_num != -1) {
            node->val = check_num;
            node->isLeaf = true;
            return node;
        }

        // 划分为 4个区域
        int left_mid = left_limit + (right_limit - left_limit) / 2;
        int top_mid = top_limit + (bottom_limit - top_limit) / 2;

        // top left
        check_num = check_rec(grid, top_limit, left_mid, top_mid, left_limit);
        if (check_num != -1) {  // 区间值全部相同, 叶子节点
            // 如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
            node->topLeft = new Node(check_num, true);
        } else {
            // 继续划分
            // 如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值
            node->topLeft = build(grid, top_limit, left_mid, top_mid, left_limit);
        }
        // top right
        check_num = check_rec(grid, top_limit, right_limit, top_mid, left_mid + 1);
        if (check_num != -1) {  // 区间值全部相同, 叶子节点
            node->topRight = new Node(check_num, true);
        } else {
            // 继续划分
            node->topRight = build(grid, top_limit, right_limit, top_mid, left_mid + 1);
        }
        // bottom Left
        check_num = check_rec(grid, top_mid + 1, left_mid, bottom_limit, left_limit);
        if (check_num != -1) {  // 区间值全部相同, 叶子节点
            node->bottomLeft = new Node(check_num, true);
        } else {
            // 继续划分
            node->bottomLeft = build(grid, top_mid + 1, left_mid, bottom_limit, left_limit);
        }
        // bottom Right
        check_num = check_rec(grid, top_mid + 1, right_limit, bottom_limit, left_mid + 1);
        if (check_num != -1) {  // 区间值全部相同, 叶子节点
            node->bottomRight = new Node(check_num, true);
        } else {
            // 继续划分
            node->bottomRight = build(grid, top_mid + 1, right_limit, bottom_limit, left_mid + 1);
        }

        return node;
    }

    // grid: nxn的方矩阵，且n必是2的次方(可以四等分)
    Node *construct(vector<vector<int>> &grid) {
        if (grid.size() == 1) {
            return new Node(grid[0][0], true);
        }

        m = grid.size() - 1;
        n = grid[0].size() - 1;
        Node *root = build(grid, 0, n, m, 0);
        return root;
    }
};

int main() {
    vector<vector<int>> nums = {{0, 1},
                                {1, 0}};
    Solution so;
    Node *node = so.construct(nums);
    cout << node->val << endl;

    return 0;
}

