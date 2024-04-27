/*************************
 * @file   : 6_min_depth.cpp
 * @encode : UTF-8
 * @note   : 二叉树的最小深度 https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 * @date   : 2024/3/10 11
 *************************/
/* 使用前序求的就是深度，使用后序求的是高度
 * 二叉树节点的深度：指从 根节点 到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
 * 二叉树节点的高度：指从 该节点 到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）
 */

#include "iostream"
#include "vector"
#include "stack"
#include "queue"
#include "algorithm"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 前序遍历
    void traversal(TreeNode *root, int cur_depth, int &min_depth) {
        if (root == nullptr) {
            return;
        }
        // 题目中说的是：最小深度是从根节点到最近叶子节点的最短路径上的节点数量
        // 左右孩子都为空的节点才是叶子节点！
        if (root->left == nullptr && root->right == nullptr) {
            min_depth = min(cur_depth, min_depth);
        }
        traversal(root->left, cur_depth + 1, min_depth);
        traversal(root->right, cur_depth + 1, min_depth);
    }

    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int ret = INT_MAX;
        int cur_depth = 1;
        traversal(root, cur_depth, ret);
        return ret;
    }


    // 后序遍历
    int get_depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = get_depth(root->left);   // 左
        int right_depth = get_depth(root->right); // 右

        // 当一个左子树为空，右不为空，这时并不是最低点
        if (root->left == nullptr && root->right != nullptr) {
            return 1 + right_depth;
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (root->left != nullptr && root->right == nullptr) {
            return 1 + left_depth;
        }
        int depth = 1 + min(left_depth, right_depth);
        return depth;
    }

    int minDepth2(TreeNode *root) {
        return get_depth(root);
    }
};

int main() {
    vector<int> tree_nums = {2, -1, 3, -1, 4, -1, 5, -1, 6};  // -1 表示 null 节点

    TreeNode *root = new TreeNode(tree_nums[0]);
    TreeNode *cur_node;
    queue<TreeNode *> que_node;
    que_node.push(root);
    for (int i = 0; !que_node.empty(); ++i) {
        cur_node = que_node.front();
        que_node.pop();

        int left_index = 2 * i + 1;
        int right_index = 2 * i + 2;

        int left_val;
        if (left_index >= tree_nums.size()) {
            left_val = -1;
        } else {
            left_val = tree_nums[left_index];
        }
        int right_val;
        if (right_index >= tree_nums.size()) {
            right_val = -1;
        } else {
            right_val = tree_nums[right_index];
        }

        if (left_val != -1) {
            TreeNode *left_node = new TreeNode(left_val);
            cur_node->left = left_node;
            que_node.push(left_node);
        }

        if (right_val != -1) {
            TreeNode *right_node = new TreeNode(right_val);
            cur_node->right = right_node;
            que_node.push(right_node);
        }
    }

    Solution so;
    cout << so.minDepth(root) << endl;
    cout << "=====================" << endl;
    cout << so.minDepth2(root) << endl;

    return 0;
}