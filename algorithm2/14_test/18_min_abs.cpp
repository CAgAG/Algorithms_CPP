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

    void traversial(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traversial(root->left);
        path.push_back(root->val);
        traversial(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        path = vector<int>();
        traversial(root);
        int ret = INT_MAX;
        for (int i = 1; i < path.size(); ++i) {
            ret = min(ret, abs(path[i] - path[i - 1]));
        }
        return ret;
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