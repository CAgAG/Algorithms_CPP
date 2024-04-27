/*************************
 * @file   : 7_node_numbers.cpp
 * @encode : UTF-8
 * @note   : 完全二叉树的节点个数 https://leetcode.cn/problems/count-complete-tree-nodes/description/
 * @date   : 2024/3/10 13
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
    void traversal(TreeNode *root, int &count) {
        if (root == nullptr) {
            return;
        }
        count += 1;
        traversal(root->left, count);
        traversal(root->right, count);
    }

    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        traversal(root, ret);
        return ret;
    }
};

int main() {
    vector<int> tree_nums = {1, 2, 3, 4, 5, 6};  // -1 表示 null 节点

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
    cout << so.countNodes(root) << endl;

    return 0;
}