/*************************
 * @file   : 9_leaf_path.cpp
 * @encode : UTF-8
 * @note   : 二叉树的所有路径 https://leetcode.cn/problems/binary-tree-paths/description/
 * @date   : 2024/3/10 14
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

    void traversal2(TreeNode *root, vector<int> &path, vector<vector<int>> &paths) {
        path.push_back(root->val);
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(vector<int>(path.begin(), path.end()));
            return;
        }

        if (root->left != nullptr) {
            traversal2(root->left, path, paths);
            path.pop_back();
        }
        if (root->right != nullptr) {
            traversal2(root->right, path, paths);
            path.pop_back();
        }
    }

    // =================================================================
    void traversal(TreeNode *root, vector<int> &path, vector<vector<int>> &paths) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(vector<int>(path.begin(), path.end()));
        }
        traversal(root->left, path, paths);
        traversal(root->right, path, paths);
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<int> path;
        vector<vector<int>> paths;

        traversal(root, path, paths);
        vector<string> ret;
        for (auto path: paths) {
            string s = "";
            for (int i = 0; i < path.size() - 1; ++i) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            ret.push_back(s);
        }
        return ret;
    }
};

int main() {
    vector<int> tree_nums = {1, 2, 3, -1, 5};  // -1 表示 null 节点

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
    for (auto path: so.binaryTreePaths(root)) {
        cout << path << endl;
    }

    return 0;
}