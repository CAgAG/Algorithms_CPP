/*************************
 * @file   : 1_loop.cpp
 * @encode : UTF-8
 * @note   : 二叉树的递归遍历
 *           https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *           https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *           https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 * @date   : 2024/3/9 19
 *************************/

#include "iostream"
#include "vector"
#include "stack"

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
    void traversal_pre(TreeNode *cur_node, vector<int> &path) {
        if (cur_node == nullptr) {
            return;
        }
        path.push_back(cur_node->val);
        traversal_pre(cur_node->left, path);
        traversal_pre(cur_node->right, path);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        traversal_pre(root, ret);
        return ret;
    }

    // 后序遍历
    void traversal_post(TreeNode *cur_node, vector<int> &path) {
        if (cur_node == nullptr) {
            return;
        }
        traversal_post(cur_node->left, path);
        traversal_post(cur_node->right, path);
        path.push_back(cur_node->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        traversal_post(root, ret);
        return ret;
    }

    // 中序遍历
    void traversal_in(TreeNode *cur_node, vector<int> &path) {
        if (cur_node == nullptr) {
            return;
        }
        traversal_in(cur_node->left, path);
        path.push_back(cur_node->val);
        traversal_in(cur_node->right, path);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        traversal_in(root, ret);
        return ret;
    }
};

int main() {
    vector<int> tree_nums = {1, -1, 2, 3};  // -1 表示 null 节点

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
    for (auto num: so.preorderTraversal(root)) {
        cout << num << " ";
    }
    cout << endl;

    for (auto num: so.postorderTraversal(root)) {
        cout << num << " ";
    }
    cout << endl;

    for (auto num: so.inorderTraversal(root)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}