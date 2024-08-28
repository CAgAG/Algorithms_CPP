/*************************
 * @file   : 38_sum_tree.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/16 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

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
    TreeNode *pre_node;

    void traver(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traver(root->right);

        if (pre_node != nullptr) {
            root->val += pre_node->val;
        }
        pre_node = root;

        traver(root->left);

    }

    TreeNode *convertBST(TreeNode *root) {
        pre_node = nullptr;
        traver(root);
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
    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(1);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    Solution so;
    print_tree(so.convertBST(root));
    return 0;
}