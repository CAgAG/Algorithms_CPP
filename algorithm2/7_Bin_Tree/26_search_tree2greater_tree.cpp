/*************************
 * @file   : 26_search_tree2greater_tree.cpp
 * @encode : UTF-8
 * @note   : 把二叉搜索树转换为累加树 https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
 * @date   : 2024/3/17 13
 *************************/
/* 累加树: 一个有序数组[2, 5, 13]，求从后到前的累加数组，也就是[20, 18, 13] */

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
private:
    TreeNode *pre_node = nullptr;
public:
    void traversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traversal(root->right);  // 翻转，先从右节点开始 ==> 相当于 倒序 遍历 递增的序列

        root->val += pre_node->val;
        pre_node = root;

        traversal(root->left);
    }

    TreeNode *convertBST(TreeNode *root) {
        pre_node = new TreeNode(0);
        traversal(root);
        return root;
    }
};


void print_tree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    print_tree(root->left);
    cout << root->val << " ";
    print_tree(root->right);
}

int main() {
    const int null_num = -100;  // 定义为 null 节点的值
    vector<int> tree_nums = {4, 1, 6, 0, 2, 5, 7, null_num, null_num, null_num, 3, null_num, null_num, null_num, 8};

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
            left_val = null_num;
        } else {
            left_val = tree_nums[left_index];
        }
        int right_val;
        if (right_index >= tree_nums.size()) {
            right_val = null_num;
        } else {
            right_val = tree_nums[right_index];
        }

        if (left_val != null_num) {
            TreeNode *left_node = new TreeNode(left_val);
            cur_node->left = left_node;
            que_node.push(left_node);
        }

        if (right_val != null_num) {
            TreeNode *right_node = new TreeNode(right_val);
            cur_node->right = right_node;
            que_node.push(right_node);
        }
    }

    Solution so;
    print_tree(so.convertBST(root));

    return 0;
}