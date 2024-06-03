/*************************
 * @file   : 15_merge_tree.cpp
 * @encode : UTF-8
 * @note   : 合并二叉树 https://leetcode.cn/problems/merge-two-binary-trees/description/
 * @date   : 2024/3/15 11
 *************************/
// 合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

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
    TreeNode *traversal(TreeNode *root1, TreeNode *root2) {

        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }

        TreeNode *ret_root = new TreeNode(0);
        if (root1 != nullptr) {
            ret_root->val += root1->val;
        }
        if (root2 != nullptr) {
            ret_root->val += root2->val;
        }

        if (root1 == nullptr) {
            ret_root->left = traversal(nullptr, root2->left);
            ret_root->right = traversal(nullptr, root2->right);
        } else if (root2 == nullptr) {
            ret_root->left = traversal(root1->left, nullptr);
            ret_root->right = traversal(root1->right, nullptr);
        } else {
            ret_root->left = traversal(root1->left, root2->left);  // 一起向左
            ret_root->right = traversal(root1->right, root2->right);  // 一起向右
        }

        return ret_root;
    }


    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        return traversal(root1, root2);
    }
};


TreeNode *build_tree(vector<int> tree_nums) {
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
    return root;
}

void print_tree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    vector<int> tree_nums = {1, 3, 2, 5};  // -1 表示 null 节点
    vector<int> tree_nums2 = {2, 1, 3, -1, 4, -1, 7};  // -1 表示 null 节点

    TreeNode *root = build_tree(tree_nums);
    TreeNode *root2 = build_tree(tree_nums2);

    Solution so;
    print_tree(so.mergeTrees(root, root2));
    cout << endl;

    return 0;
}