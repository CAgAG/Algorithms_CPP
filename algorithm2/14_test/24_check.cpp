/*************************
 * @file   : 24_check.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/12 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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
    bool isSymmetric(TreeNode *root) {

        queue<TreeNode *> left_que;
        queue<TreeNode *> right_que;

        left_que.push(root->left);
        right_que.push(root->right);

        while (!left_que.empty() && !right_que.empty()) {

            TreeNode *l_node = left_que.front();
            left_que.pop();
            TreeNode *r_node = right_que.front();
            right_que.pop();

            if (l_node == nullptr && r_node == nullptr) {
                continue;
            }
            if (l_node != nullptr && r_node == nullptr) {
                return false;
            }
            if (l_node == nullptr && r_node != nullptr) {
                return false;
            }
            if (l_node->val != r_node->val) {
                return false;
            }

            left_que.push(l_node->left);
            right_que.push(r_node->right);

            left_que.push(l_node->right);
            right_que.push(r_node->left);

        }
        return true;
    }
};


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution so;
    cout << so.isSymmetric(root) << endl;

}