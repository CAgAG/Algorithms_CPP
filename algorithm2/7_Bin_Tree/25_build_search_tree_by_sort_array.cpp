/*************************
 * @file   : 25_build_search_tree_by_sort_array.cpp
 * @encode : UTF-8
 * @note   : 将有序数组转换为二叉搜索树 https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 * @date   : 2024/3/17 13
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
    // 总是选中间的数作为节点
    TreeNode *traversal(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid_index = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid_index]);

        root->left = traversal(nums, left, mid_index - 1);
        root->right = traversal(nums, mid_index + 1, right);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        return traversal(nums, 0, nums.size() - 1);
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
    vector<int> tree_nums = {-10, -3, 0, 5, 9};

    Solution so;
    print_tree(so.sortedArrayToBST(tree_nums));

    return 0;
}