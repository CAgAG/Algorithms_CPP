/*************************
 * @file   : 2_level_loop.cpp
 * @encode : UTF-8
 * @note   : 二叉树的层序遍历 https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 * @date   : 2024/3/9 20
 *************************/
 // https://www.programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ret;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            int que_size = que.size();  // 某一层的所有节点数
            vector<int> sub_ret;

            TreeNode *cur_node;
            // 这里一定要使用固定大小 size，不要使用que.size()，因为que.size是不断变化的; 用于划分层节点数
            for (int i = 0; i < que_size; ++i) {  // 将旧队列全部弹出
                cur_node = que.front();
                que.pop();

                sub_ret.push_back(cur_node->val);
                if (cur_node->left != nullptr) {
                    que.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    que.push(cur_node->right);
                }
            }
            ret.push_back(sub_ret);
        }
        return ret;
    }
};


int main() {
    vector<int> tree_nums = {3, 9, 20, -1, -1, 15, 7};  // -1 表示 null 节点

    TreeNode *root = new TreeNode(tree_nums[0]);
    TreeNode *cur_node;
    stack<TreeNode *> stack_node;
    stack_node.push(root);
    for (int i = 0; !stack_node.empty(); ++i) {
        cur_node = stack_node.top();
        stack_node.pop();

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

        if (right_val != -1) {
            TreeNode *right_node = new TreeNode(right_val);
            cur_node->right = right_node;
            stack_node.push(right_node);
        }

        if (left_val != -1) {
            TreeNode *left_node = new TreeNode(left_val);
            cur_node->left = left_node;
            stack_node.push(left_node);
        }
    }

    Solution so;
    for (auto nums: so.levelOrder(root)) {
        for (auto num: nums) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}