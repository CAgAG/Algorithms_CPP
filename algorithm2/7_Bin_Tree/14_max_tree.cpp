/*************************
 * @file   : 14_max_tree.cpp
 * @encode : UTF-8
 * @note   : 最大二叉树 https://leetcode.cn/problems/maximum-binary-tree/description/
 * @date   : 2024/3/14 18
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
    TreeNode *traversal(vector<int> nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }

        // 找到最大值的数及其位置
        int max_value = -1;
        int max_value_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max_value) {
                max_value = nums[i];
                max_value_index = i;
            }
        }

        // 最大值左边
        vector<int> left_range(nums.begin(), nums.begin() + max_value_index);
        // 最大值右边
        vector<int> right_range(nums.begin() + max_value_index + 1, nums.end());

        // 递归寻找
        TreeNode *root = new TreeNode(max_value);
        root->left = traversal(left_range);
        root->right = traversal(right_range);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return traversal(nums);
    }
};

void print_tree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution so;
    TreeNode *root = so.constructMaximumBinaryTree(nums);
    print_tree(root);
    cout << endl;
    return 0;
}