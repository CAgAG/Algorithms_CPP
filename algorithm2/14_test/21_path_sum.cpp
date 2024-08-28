/*************************
 * @file   : 21_path_sum.cpp
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
    int path_sum = 0;

    bool traversial(TreeNode *root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr && path_sum == targetSum) {
            return true;
        }

        if (root->left != nullptr) {
            path_sum += root->left->val;
            if (traversial(root->left, targetSum)) {
                return true;
            }
            path_sum -= root->left->val;
        }
        if (root->right != nullptr) {
            path_sum += root->right->val;
            if (traversial(root->right, targetSum)) {
                return true;
            }
            path_sum -= root->right->val;
        }
        return false;
    }


    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        path_sum = root->val;
        return traversial(root, targetSum);
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution so;
    cout << so.hasPathSum(root, 22) << endl;
}