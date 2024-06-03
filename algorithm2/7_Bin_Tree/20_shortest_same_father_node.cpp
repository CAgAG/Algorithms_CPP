/************************* key
 * @file   : 20_shortest_same_father_node.cpp
 * @encode : UTF-8
 * @note   : 二叉树的最近公共祖先 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 * @date   : 2024/3/15 13
 *************************/
/* 一个节点也可以是它自己的祖先 */
/* 注意:
 *  树中节点数目在范围 [2, 105] 内
 *  所有 Node.val 互不相同
 *  p != q
 *  p 和 q 均存在于给定的二叉树中
 */
// https://www.programmercarl.com/0236.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.html#%E6%80%9D%E8%B7%AF

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
    TreeNode *traversal(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 返回条件
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }

        TreeNode *left_node = traversal(root->left, p, q);
        TreeNode *right_node = traversal(root->right, p, q);

        // 回溯
        if (left_node != nullptr && right_node == nullptr) {
            return left_node;
        } else if (left_node == nullptr && right_node != nullptr) {
            return right_node;
        } else if (left_node == nullptr && right_node == nullptr) {
            return nullptr;
        } else {  // left_node != nullptr && right_node != nullptr
            return root;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *ret = traversal(root, p, q);
        return ret;
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
    const int null_num = -100;  // 定义为 null 节点的值

    // 树中节点数目在范围 [2, 105] 内
    vector<int> tree_nums = {-1, 0, 3, -2, 4, null_num, null_num, 8};

    // p 和 q 均存在于给定的二叉树中
    // p != q
    TreeNode *p;
    TreeNode *q;
    TreeNode *root = new TreeNode(tree_nums[0]);
    TreeNode *cur_node;
    queue<TreeNode *> que_node;
    que_node.push(root);
    for (int i = 0; !que_node.empty(); ++i) {
        cur_node = que_node.front();
        que_node.pop();

        // p
        if (cur_node->val == 8) {
            p = cur_node;
        }
        // q
        if (cur_node->val == 4) {
            q = cur_node;
        }

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
    print_tree(so.lowestCommonAncestor(root, p, q));

    return 0;
}