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
    int ret;

    void traver(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            ret += root->left->val;
        }

        traver(root->left);
        traver(root->right);

    }

    int sumOfLeftLeaves(TreeNode *root) {
        ret = 0;
        traver(root);
        return ret;
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
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution so;
    cout << so.sumOfLeftLeaves(root) << endl;
    return 0;
}