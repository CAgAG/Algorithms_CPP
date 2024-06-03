/*************************
 * @file   : 13_build_tree.cpp
 * @encode : UTF-8
 * @note   : 从中序与后序遍历序列构造二叉树 https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
    TreeNode *traversal(vector<int> inorder, vector<int> postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        int target_num = postorder[postorder.size() - 1];
        TreeNode *new_node = new TreeNode(target_num);
        // 叶子节点
        if (postorder.size() == 1) {
            return new_node;
        }

        // 找到分割点，在中序中找到对应的点的索引
        int in_target_index = 0;
        for (; in_target_index < inorder.size(); ++in_target_index) {
            if (inorder[in_target_index] == target_num) {
                break;
            }
        }

        // 切割中序数组
        vector<int> left_in(inorder.begin(), inorder.begin() + in_target_index);
        vector<int> right_in(inorder.begin() + in_target_index + 1, inorder.end());
        // 切割后序数组，使用对应中序左子区间的长度
        vector<int> left_post(postorder.begin(), postorder.begin() + left_in.size());
        vector<int> right_post(postorder.begin() + left_in.size(), postorder.end() - 1);  // 排除最后一个

        new_node->left = traversal(left_in, left_post);  // 对左区间搜索
        new_node->right = traversal(right_in, right_post);  // 对右区间搜索
        return new_node;
    }


    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return traversal(inorder, postorder);
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
    const int null_num = -1;  // 定义为 null 节点的值

    vector<int> inorder_tree_nums = {9, 3, 15, 20, 7};    // 左 中 右
    vector<int> postorder_tree_nums = {9, 15, 7, 20, 3};  // 左 右 中
    // 注意两个顺序的 的第一个左的位置是一样的
    // 从 中 来 推断 左

    Solution so;
    TreeNode *root = so.buildTree(inorder_tree_nums, postorder_tree_nums);
    print_tree(root);
    cout << endl;
    return 0;
}