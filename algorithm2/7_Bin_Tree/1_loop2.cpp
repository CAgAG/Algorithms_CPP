/*************************
 * @file   : 1_loop.cpp
 * @encode : UTF-8
 * @note   : 二叉树的迭代遍历
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
        if (root == nullptr) {
            return {};
        }

        vector<int> ret;
        stack<TreeNode *> stack_node;
        TreeNode *cur_node;
        stack_node.push(root);
        while (!stack_node.empty()) {
            cur_node = stack_node.top();
            stack_node.pop();
            ret.push_back(cur_node->val);

            // 注意出栈顺序，先进右节点
            if (cur_node->right != nullptr) {
                stack_node.push(cur_node->right);
            }
            if (cur_node->left != nullptr) {
                stack_node.push(cur_node->left);
            }
        }
        return ret;
    }

    // 后序遍历
    /* 再来看后序遍历，先序遍历是中左右，后续遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，
     * 然后在反转 ret数组，输出的结果顺序就是左右中了 */
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ret;
        stack<TreeNode *> stack_node;
        TreeNode *cur_node;
        stack_node.push(root);
        while (!stack_node.empty()) {
            cur_node = stack_node.top();
            stack_node.pop();
            ret.push_back(cur_node->val);

            // 注意出栈顺序，修改为 中右左
            if (cur_node->left != nullptr) {
                stack_node.push(cur_node->left);
            }
            if (cur_node->right != nullptr) {
                stack_node.push(cur_node->right);
            }
        }
        reverse(ret.begin(), ret.end()); // 将结果反转之后就是左右中的顺序了
        return ret;
    }

    // 中序遍历
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ret;
        stack<TreeNode *> stack_node;
        TreeNode *cur_node = root;
        while (!stack_node.empty() || cur_node != nullptr) {
            // 先去找 左节点，直到底
            if (cur_node != nullptr) {
                stack_node.push(cur_node);  // 即表示 left 也是 mid
                cur_node = cur_node->left;
            } else {
                cur_node = stack_node.top();
                stack_node.pop();

                ret.push_back(cur_node->val);
                cur_node = cur_node->right;
            }
        }
        return ret;
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