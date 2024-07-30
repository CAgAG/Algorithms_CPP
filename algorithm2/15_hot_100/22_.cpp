/*************************
 * @file   : 22_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/23 11
 *************************/

#include "iostream"
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
    int  ans = 0;

    int traver(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_h = traver(root->left);
        int right_h = traver(root->right);

        cout << "=================" << endl;
        cout << root->val << " : " << left_h << ", " << right_h << endl;
        cout << "=================" << endl;

        ans = max(ans, left_h + right_h + 1);
        return max(left_h, right_h) + 1;

    }

    int diameterOfBinaryTree(TreeNode *root) {
        traver(root);
        return ans - 1;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution so;
    cout << so.diameterOfBinaryTree(root) << endl;

    return 0;
}