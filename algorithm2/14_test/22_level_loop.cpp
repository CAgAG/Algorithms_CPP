/*************************
 * @file   : 22_level_loop.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/12 14
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode *> que;
        vector<vector<int>> ret;
        que.push(root);

        while (!que.empty()) {

            int que_length = que.size();
            vector<int> level_nodes;
            for (int i = 0; i < que_length; ++i) {
                TreeNode *cur_node = que.front();
                que.pop();
                level_nodes.push_back(cur_node->val);

                if (cur_node->left != nullptr) {
                    que.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    que.push(cur_node->right);
                }
            }
            ret.push_back(level_nodes);
        }
        return ret;
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
    for (auto as: so.levelOrder(root)) {
        for (auto a: as) {
            cout << a << " ";
        }
        cout << endl;
    }
}