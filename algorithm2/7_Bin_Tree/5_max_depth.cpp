/*************************
 * @file   : 5_max_depth.cpp
 * @encode : UTF-8
 * @note   : 二叉树的最大深度 https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
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
    void traversal(TreeNode *root, int cur_depth, int &max_depth) {
        if (root == nullptr) {
            return;
        }
        max_depth = max(cur_depth, max_depth);
        traversal(root->left, cur_depth + 1, max_depth);
        traversal(root->right, cur_depth + 1, max_depth);
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int ret = 1;
        int cur_depth = 1;
        traversal(root, cur_depth, ret);
        return ret;
    }

    // 后序遍历
    int get_depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftdepth = get_depth(root->left);       // 左
        int rightdepth = get_depth(root->right);     // 右
        int depth = 1 + max(leftdepth, rightdepth);  // 中
        cout << leftdepth << ", " << rightdepth << endl;
        return depth;
    }

    int maxDepth2(TreeNode *root) {
        return get_depth(root);
    }
};

int main() {
    vector<int> tree_nums = {3, 9, 20, -1, -1, 15, 7};  // -1 表示 null 节点

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
    cout << so.maxDepth(root) << endl;
    cout << "=====================" << endl;
    cout << so.maxDepth2(root) << endl;

    return 0;
}