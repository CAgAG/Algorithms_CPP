/*************************
 * @file   : 4_symmetric_tree.cpp
 * @encode : UTF-8
 * @note   : 对称二叉树 https://leetcode.cn/problems/symmetric-tree/description/
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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode *> que_left;
        queue<TreeNode *> que_right;

        que_left.push(root->left);
        que_right.push(root->right);
        while (!que_left.empty() && !que_right.empty()) {
            TreeNode *left_node = que_left.front();
            que_left.pop();
            TreeNode *right_node = que_right.front();
            que_right.pop();

            if (left_node == nullptr && right_node == nullptr) {
                continue;
            }

            if (left_node == nullptr || right_node == nullptr || left_node->val != right_node->val) {
                return false;
            }

            que_left.push(left_node->left);
            que_left.push(left_node->right);
            que_right.push(right_node->right);
            que_right.push(right_node->left);
        }
        return true;
    }
};

int main() {
    vector<int> tree_nums = {1, 2, 2, 3, 4, 4, 3};  // -1 表示 null 节点

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
    cout << so.isSymmetric(root) << endl;

    return 0;
}