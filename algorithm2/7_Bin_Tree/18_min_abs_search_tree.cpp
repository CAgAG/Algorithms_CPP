/*************************
 * @file   : 18_min_abs_search_tree.cpp
 * @encode : UTF-8
 * @note   : 二叉搜索树的最小绝对差 https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
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
    // 中序遍历
    void traversal(TreeNode *root, vector<int> &path) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left, path);
        path.push_back(root->val);
        traversal(root->right, path);
    }


    int getMinimumDifference(TreeNode *root) {
        vector<int> path;
        traversal(root, path);
        int ret = INT_MAX;
        for (int i = 1; i < path.size(); i++) {
            ret = min(ret, abs(path[i] - path[i - 1]));
        }
        return ret;
    }
// ===========================================
/* 递归中记录前一个节点的指针 */
private:
    int result = INT_MAX;
    TreeNode *pre = nullptr;

    void traversal2(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        traversal2(cur->left);   // 左
        if (pre != nullptr) {    // 中
            result = min(result, cur->val - pre->val);
        }
        pre = cur; // 记录前一个
        traversal2(cur->right);  // 右
    }

public:
    int getMinimumDifference2(TreeNode *root) {
        traversal2(root);
        return result;
    }
};

int main() {
    const int null_num = -100;  // 定义为 null 节点的值

    vector<int> tree_nums = {4, 2, 6, 1, 3};

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
    cout << so.getMinimumDifference(root) << endl;
    cout << so.getMinimumDifference2(root) << endl;

    return 0;
}