/*************************
 * @file   : 1_loop3.cpp
 * @encode : UTF-8
 * @note   : 二叉树的统一迭代写法
 *           https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *           https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
 *           https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 * @date   : 2024/3/9 19
 *************************/

#include "iostream"
#include "vector"
#include "stack"
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
    // 前序遍历
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();

                // ===========================================================
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左
                st.push(node);                          // 中
                st.push(NULL);
                // ===========================================================
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

    // 后序遍历
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();

                // ===========================================================
                st.push(node);                          // 中
                st.push(NULL);
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左
                // ===========================================================
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

    // 中序遍历
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {  // 栈: |右 中 null 左 ->
                st.pop(); // 将该节点先弹出，下面再将右中左节点添加到栈中

                /* 可以看出我们将访问的节点直接加入到栈中，但如果是处理的节点则后面放入一个空节点，
                 * 这样只有空节点弹出的时候，才将下一个节点放进结果集。*/
                // ===========================================================
                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）
                st.push(node); // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
                if (node->left) st.push(node->left);  // 添加左节点（空节点不入栈）
                // ===========================================================
            } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           // 将空节点弹出
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }
};

int main() {
    vector<int> tree_nums = {1, -1, 2, 3};  // -1 表示 null 节点

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
    for (auto num: so.preorderTraversal(root)) {
        cout << num << " ";
    }
    cout << endl;

    for (auto num: so.postorderTraversal(root)) {
        cout << num << " ";
    }
    cout << endl;

    for (auto num: so.inorderTraversal(root)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}