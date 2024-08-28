/*************************
 * @file   : 20_left_leaf_sum.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/12 14
 *************************/

#include "iostream"
#include "vector"
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
    int ret = 0;

    void traversial(TreeNode *root) {

        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                ret += root->left->val;
            }
            traversial(root->left);
        }
        if (root->right != nullptr) {
            traversial(root->right);
        }

    }


    int sumOfLeftLeaves(TreeNode *root) {
        traversial(root);
        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution so;
    cout << so.sumOfLeftLeaves(root) << endl;
}