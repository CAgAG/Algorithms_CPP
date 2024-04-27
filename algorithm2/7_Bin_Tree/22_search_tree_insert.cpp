/*************************
 * @file   : 22_search_tree_insert.cpp
 * @encode : UTF-8
 * @note   : 二叉搜索树中的插入操作 https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/
 * @date   : 2024/3/17 12
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
private:
    TreeNode *pre_node = nullptr;
public:
    void traversal(TreeNode *root, int val) {
        if (root == nullptr) {
            TreeNode *new_node = new TreeNode(val);
            if (pre_node->val > val) {
                pre_node->left = new_node;
            } else {
                pre_node->right = new_node;
            }
            return;
        }

        pre_node = root;
        if (root->val > val) {
            traversal(root->left, val);
        }
        if (root->val < val) {
            traversal(root->right, val);
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        pre_node = nullptr;
        traversal(root, val);
        return root;
    }
    // ======================================================
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
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
    vector<int> tree_nums = {4, 2, 7, 1, 3};

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
    print_tree(so.insertIntoBST(root, 5));

    return 0;
}