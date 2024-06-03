/************************* key
 * @file   : 8_check_balanced_tree.cpp
 * @encode : UTF-8
 * @note   : 平衡二叉树 https://leetcode.cn/problems/balanced-binary-tree/
 * @date   : 2024/3/10 14
 *************************/
// 一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1

#include "iostream"
#include "vector"
#include "stack"
#include "queue"
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
    // -1 表示已经不是平衡二叉树了，否则返回值是以该节点为根节点树的高度
    // 返回值就是当前遍历树的状态
    int get_height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_height = get_height(root->left);
        if (left_height == -1) {
            return -1;
        }
        int right_height = get_height(root->right);
        if (right_height == -1) {
            return -1;
        }

        int ret;
        if (abs(left_height - right_height) > 1) {
            ret = -1;
        } else {
            ret = 1 + max(left_height, right_height);
        }
        return ret;
    }

    bool isBalanced(TreeNode *root) {
        int height = get_height(root);
        if (height == -1) {
            return false;
        } else {
            return true;
        }
    }
};

int main() {
    vector<int> tree_nums = {3, 9, 20, -1, -1, 15, 7};  // -1 表示 null 节点

    TreeNode *root = new TreeNode(tree_nums[0]);
    TreeNode *cur_node;
    queue<TreeNode *> que_node;
    que_node.push(root);
    for (int i = 0; !que_node.empty(); ++i) {
        cur_node = que_node.front();
        que_node.pop();

        int left_index = 2 * i + 1;
        int right_index = 2 * i + 2;

        int left_val;
        if (left_index >= tree_nums.size()) {
            left_val = -1;
        } else {
            left_val = tree_nums[left_index];
        }
        int right_val;
        if (right_index >= tree_nums.size()) {
            right_val = -1;
        } else {
            right_val = tree_nums[right_index];
        }

        if (left_val != -1) {
            TreeNode *left_node = new TreeNode(left_val);
            cur_node->left = left_node;
            que_node.push(left_node);
        }

        if (right_val != -1) {
            TreeNode *right_node = new TreeNode(right_val);
            cur_node->right = right_node;
            que_node.push(right_node);
        }
    }

    Solution so;
    cout << so.isBalanced(root) << endl;

    return 0;
}