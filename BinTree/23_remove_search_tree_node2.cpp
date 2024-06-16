/*************************
 * @file   : 23_remove_search_tree_node2.cpp
 * @encode : UTF-8
 * @note   : 删除二叉搜索树中的节点 https://leetcode.cn/problems/delete-node-in-a-bst/description/
 * @date   : 2024/6/16 12
 *************************/

#include "iostream"
#include "vector"
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
    TreeNode *traver(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                TreeNode *tp = root->left;
                // 不要 delete root;
                return tp;
            } else if (root->left == nullptr && root->right != nullptr) {
                TreeNode *tp = root->right;
                // 不要 delete root;
                return tp;
            } else {
                // 找 直接后继
                TreeNode *rl_node = root->right;
                while (rl_node->left != nullptr) {
                    rl_node = rl_node->left;
                }

                // 删除后继节点
                root->right = traver(root->right, rl_node->val);

                // 代替删除节点
                rl_node->left = root->left;
                rl_node->right = root->right;
                return rl_node;
            }

        }

        if (key < root->val) {
            root->left = traver(root->left, key);
        }

        if (key > root->val) {
            root->right = traver(root->right, key);
        }
        return root;
    }


    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        return traver(root, key);
    }
};

void print_tree(TreeNode *node) {
    if (node == nullptr) {
        return;
    }

    cout << node->val << " ";
    print_tree(node->left);
    print_tree(node->right);
}


int main() {
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    Solution so;
    print_tree(so.deleteNode(root, 5));

    return 0;
}