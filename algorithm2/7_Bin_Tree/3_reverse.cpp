/*************************
 * @file   : 3_reverse.cpp
 * @encode : UTF-8
 * @note   : 翻转二叉树 https://leetcode.cn/problems/invert-binary-tree/description/
 * @date   : 2024/3/10 10
 *************************/

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
    void traversal_pre(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        // 左右孩子互换
        TreeNode *tp = node->left;
        node->left = node->right;
        node->right = tp;

        traversal_pre(node->left);
        traversal_pre(node->right);
    }

    TreeNode *invertTree(TreeNode *root) {
        TreeNode *cur_node = root;
        traversal_pre(cur_node);
        return root;
    }
};

void print_tree(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    cout << node->val << " ";
    print_tree(node->left);
    print_tree(node->right);
}


int main() {
    vector<int> tree_nums = {4, 2, 7, 1, 3, 6, 9};  // -1 表示 null 节点

    TreeNode *root = new TreeNode(tree_nums[0]);
    TreeNode *cur_node;
    stack<TreeNode *> stack_node;
    stack_node.push(root);
    for (int i = 0; !stack_node.empty(); ++i) {
        cur_node = stack_node.top();
        stack_node.pop();

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

        if (right_val != -1) {
            TreeNode *right_node = new TreeNode(right_val);
            cur_node->right = right_node;
            stack_node.push(right_node);
        }

        if (left_val != -1) {
            TreeNode *left_node = new TreeNode(left_val);
            cur_node->left = left_node;
            stack_node.push(left_node);
        }
    }

    Solution so;
    TreeNode *ret = so.invertTree(root);
    print_tree(ret);

    return 0;
}