/*************************
 * @file   : 24_fix_search_tree.cpp
 * @encode : UTF-8
 * @note   : 修剪二叉搜索树 https://leetcode.cn/problems/trim-a-binary-search-tree/description/
 * @date   : 2024/3/17 13
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
    TreeNode *traversal(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        // ==> 拦截 不在范围内的节点
        // 只返回 在区间内的节点
        if (root->val < low) {
            // 寻找符合区间[low, high]的节点
            TreeNode *right_tree = traversal(root->right, low, high);
            return right_tree;
        }

        if (root->val > high) {
            // 寻找符合区间[low, high]的节点
            TreeNode *left_tree = traversal(root->left, low, high);
            return left_tree;
        }

        // root->left接入符合条件的左子树
        root->left = traversal(root->left, low, high);
        // root->right接入符合条件的右子树
        root->right = traversal(root->right, low, high);
        return root;
    }

    TreeNode *trimBST(TreeNode *root, int low, int high) {
        return traversal(root, low, high);
    }
};

void print_tree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    print_tree(root->left);
    cout << root->val << " ";
    print_tree(root->right);
}

int main() {
    const int null_num = -100;  // 定义为 null 节点的值
    vector<int> tree_nums = {3, 0, 4, null_num, 2, null_num, null_num, 1};

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
            left_val = null_num;
        } else {
            left_val = tree_nums[left_index];
        }
        int right_val;
        if (right_index >= tree_nums.size()) {
            right_val = null_num;
        } else {
            right_val = tree_nums[right_index];
        }

        if (left_val != null_num) {
            TreeNode *left_node = new TreeNode(left_val);
            cur_node->left = left_node;
            que_node.push(left_node);
        }

        if (right_val != null_num) {
            TreeNode *right_node = new TreeNode(right_val);
            cur_node->right = right_node;
            que_node.push(right_node);
        }
    }

    Solution so;
    print_tree(so.trimBST(root, 1, 3));

    return 0;
}