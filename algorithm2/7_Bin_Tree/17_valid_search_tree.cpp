/*************************
 * @file   : 17_valid_search_tree.cpp
 * @encode : UTF-8
 * @note   : 验证二叉搜索树 https://leetcode.cn/problems/validate-binary-search-tree/description/
 * @date   : 2024/3/15 11
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
    // 中序遍历
    void traversal(TreeNode *root, vector<int> &path) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left, path);
        path.push_back(root->val);
        traversal(root->right, path);
    }


    bool isValidBST(TreeNode *root) {
        vector<int> path;
        traversal(root, path);
        for (int i = 1; i < path.size(); i++) {
            // 注意要小于等于，搜索树里不能有相同元素
            if (path[i] <= path[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    const int null_num = -100;  // 定义为 null 节点的值

    vector<int> tree_nums = {5, 1, 4, null_num, null_num, 3, 6};

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
    cout << so.isValidBST(root) << endl;

    return 0;
}