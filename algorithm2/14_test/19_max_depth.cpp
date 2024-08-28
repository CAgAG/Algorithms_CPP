/*************************
 * @file   : 19_max_depth.cpp
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

    void traversial(TreeNode *root, int cur_depth) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            ret = max(ret, cur_depth);
        }

        traversial(root->left, cur_depth + 1);
        traversial(root->right, cur_depth + 1);
    }


    int maxDepth(TreeNode *root) {
        traversial(root, 1);
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
    cout << so.maxDepth(root) << endl;
}