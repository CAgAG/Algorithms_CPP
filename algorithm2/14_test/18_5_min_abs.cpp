/*************************
 * @file   : 18_min_abs.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/12 14
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

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
    vector<int> path;
    int cur_h = 0;

    int traversial(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_h = traversial(root->left);
        int right_h = traversial(root->right);

        cout << root->val << " " << max(left_h, right_h) + 1 << endl;

        return max(left_h, right_h) + 1;
    }

    int getMinimumDifference(TreeNode *root) {
        return traversial(root);
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution so;
    cout << so.getMinimumDifference(root) << endl;
}