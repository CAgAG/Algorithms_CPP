/*************************
 * @file   : 37_search_tree_insert.cpp
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }

        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
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
    int key = 5;

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution so;
    print_tree(so.insertIntoBST(root, key));
    return 0;
}