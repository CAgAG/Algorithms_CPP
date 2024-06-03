/*************************
 * @file   : 19_max_count_search_tree.cpp
 * @encode : UTF-8
 * @note   : 二叉搜索树中的众数 https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 * @date   : 2024/3/15 12
 *************************/

/* 要知道中序遍历下，输出的二叉搜索树节点的数值是有序序列。
 * 有了这个特性，验证二叉搜索树，就相当于变成了判断一个序列是不是递增的了。*/

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
    int num_count = 0;
    int max_num_count = 0;  // 记录可能的众数

    // pre_node: 上一个最大的众数
    void traversal(TreeNode *root, TreeNode *&pre_node, vector<int> &ret) {
        if (root == nullptr) {
            return;
        }
        // 中序遍历
        // 相同的数是邻近的
        traversal(root->left, pre_node, ret);
        // 第一个节点
        if (pre_node == nullptr) {
            num_count = 1;
        } else {
            if (pre_node->val == root->val) {
                num_count++;
            } else {
                num_count = 1;
            }
        }
        // 如果和最大值相同，放进result中
        if (num_count == max_num_count) {
            ret.push_back(root->val);
        }

        // 大于最大值就更新
        if (num_count > max_num_count) {
            max_num_count = num_count;
            ret.clear();
            ret.push_back(root->val);
        }
        pre_node = root;
        traversal(root->right, pre_node, ret);
    }

    vector<int> findMode(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val};
        }

        TreeNode *pre_node = nullptr;
        vector<int> ret;
        traversal(root, pre_node, ret);
        return ret;
    }
};

int main() {
    const int null_num = -100;  // 定义为 null 节点的值

    vector<int> tree_nums = {1, null_num, 2, 2};

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
    for (auto num: so.findMode(root)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}