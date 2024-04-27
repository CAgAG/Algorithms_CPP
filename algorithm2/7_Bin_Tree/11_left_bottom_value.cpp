/*************************
 * @file   : 10_left_leaf.cpp
 * @encode : UTF-8
 * @note   : 找树左下角的值 https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 * @date   : 2024/3/13 20
 *************************/

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
    void traversal(TreeNode *root, pair<int, int> &ret, int depth) {
        if (root->left != nullptr) {  // 左节点
            if (depth > ret.first) {  // 不需要判断是否是叶子节点, 因为深度已经可以标记了
                ret = {depth, root->left->val};
            }
            traversal(root->left, ret, depth + 1);
        }

        if (root->right != nullptr) {
            if (depth > ret.first) {  // 比左节点更深
                ret = {depth, root->right->val};
            }
            traversal(root->right, ret, depth + 1);
        }

    }

    int findBottomLeftValue(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        pair<int, int> ret = {-1, 0};  // depth, value
        int depth = 0;
        traversal(root, ret, depth);
        return ret.second;
    }
};

int main() {
    vector<int> tree_nums = {1, -1, 2};  // -1 表示 null 节点

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
    cout << so.findBottomLeftValue(root) << endl;

    return 0;
}