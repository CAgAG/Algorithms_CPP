/*************************
 * @file   : 12_target_sum_path.cpp
 * @encode : UTF-8
 * @note   : 路径总和 https://leetcode.cn/problems/path-sum/description/
 * @date   : 2024/3/13 21
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
    // 无参数: 搜索整棵树
    void traversal(TreeNode *root, bool &ret, int &path_sum, int targetSum) {
        if (ret) {  // 达到条件就不需要计算了
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {  // 到达叶子节点
            if (path_sum == targetSum) {
                ret = true;
            }
            return;
        }

        if (root->left != nullptr) {
            path_sum += root->left->val;  // 加路径的值
            traversal(root->left, ret, path_sum, targetSum);
            path_sum -= root->left->val;  // 回退路径值
        }

        if (root->right != nullptr) {
            path_sum += root->right->val;
            traversal(root->right, ret, path_sum, targetSum);
            path_sum -= root->right->val;
        }
    }

    // 有参数: 只搜索一条路径
    bool traversal2(TreeNode *cur, int count) {  // count 初始值不是0, 而是题目要求的目标值
        if (!cur->left && !cur->right && count == 0) return true; // 遇到叶子节点，并且计数为0. 也就是等于目标值的路径
        if (!cur->left && !cur->right) return false; // 遇到叶子节点直接返回. 仅仅只是到达叶子节点

        if (cur->left != nullptr) { // 左
            count -= cur->left->val; // 递归，处理节点;
            if (traversal2(cur->left, count)) return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }
        if (cur->right != nullptr) { // 右
            count -= cur->right->val; // 递归，处理节点;
            if (traversal2(cur->right, count)) return true;
            count += cur->right->val; // 回溯，撤销处理结果
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        bool ret = false;
        int path_sum = root->val;
        traversal(root, ret, path_sum, targetSum);
        return ret;
    }
};

int main() {
    const int null_num = -100;  // 定义为 null 节点的值

    vector<int> tree_nums = {1, -2, -3, 1, 3, -2, null_num, -1};

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
    cout << so.hasPathSum(root, 3) << endl;

    return 0;
}