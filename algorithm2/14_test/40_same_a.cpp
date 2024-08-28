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
    TreeNode *traver(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode *left_node = traver(root->left, p, q);
        TreeNode *right_node = traver(root->right, p, q);

        if (left_node == nullptr && right_node == nullptr) {
            return nullptr;
        } else if (left_node != nullptr && right_node == nullptr) {
            return left_node;
        } else if (left_node == nullptr & right_node != nullptr) {
            return right_node;
        } else {
            return root;
        }
    }


    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return traver(root, p, q);
    }
};

int main() {
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;
    TreeNode *q = root->right->right;

    Solution so;
    cout << so.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}