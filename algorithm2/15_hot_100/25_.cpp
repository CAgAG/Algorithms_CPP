
/*************************
 * @file   : 22_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/23 11
 *************************/

#include "iostream"
#include "queue"
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
    void traver(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        // 右子树移到左子树的最右边
        if (root->left != nullptr) {
            TreeNode *tp = root->right;

            TreeNode *lr_node = root->left;
            while (lr_node->right != nullptr) {
                lr_node = lr_node->right;
            }
            lr_node->right = tp;

            root->right = root->left;
            root->left = nullptr;
        }

        traver(root->right);
    }


    void flatten(TreeNode *root) {
        traver(root);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution so;
    so.flatten(root);

    TreeNode *cur_node = root;
    while (cur_node != nullptr) {
        cout << cur_node->val << " ";
        cur_node = cur_node->right;
    }
    cout << endl;

    return 0;
}