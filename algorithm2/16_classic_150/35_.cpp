/*************************
 * @file   : 34_.cpp
 * @encode : UTF-8
 * @note   : 二叉树的锯齿形层序遍历 https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/17 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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
    queue<TreeNode *> que;

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }

        que.push(root);
        bool reverse_flag = false;
        while (!que.empty()) {
            int q_len = que.size();

            vector<int> level_node;
            for (int i = 0; i < q_len; ++i) {
                TreeNode *node = que.front();
                que.pop();

                level_node.push_back(node->val);

                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            if (reverse_flag) {
                reverse(level_node.begin(), level_node.end());
            }
            ret.push_back(level_node);
            reverse_flag = !reverse_flag;
        }
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
    for (auto c: so.zigzagLevelOrder(root)) {
        for (auto s: c) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}