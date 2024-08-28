/*************************
 * @file   : 23_revise_tree.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/12 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *tp = root->left;
        root->left = root->right;
        root->right = tp;

        invertTree(root->left);
        invertTree(root->right);
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
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution so;
    print_tree(so.invertTree(root));

}