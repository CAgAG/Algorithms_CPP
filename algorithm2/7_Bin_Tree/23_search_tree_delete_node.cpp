/*************************
 * @file   : 23_search_tree_delete_node.cpp
 * @encode : UTF-8
 * @note   : 删除二叉搜索树中的节点 https://leetcode.cn/problems/delete-node-in-a-bst/description/
 * @date   : 2024/3/17 12
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
    /* 第一种情况：没找到删除的节点，遍历到空节点直接返回了
     * 找到删除的节点
     *   第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
     *   第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
     *   第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
     *   第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。
     */
    TreeNode *traversal(TreeNode *root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == val) {  // 找到了节点
            if (root->left == nullptr && root->right == nullptr) {  // 2.左右节点均为空
                delete root;
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) { // 4.
                TreeNode *tp_node = root->left;
                delete root;
                return tp_node;
            } else if (root->left == nullptr && root->right != nullptr) {  // 3.
                TreeNode *tp_node = root->right;
                delete root;
                return tp_node;
            } else {  // 5.
                TreeNode *move_node = root->left;
                TreeNode *rleft_node = root->right;
                while (rleft_node->left != nullptr) {
                    rleft_node = rleft_node->left;
                }
                rleft_node->left = move_node;

                TreeNode *tp_node = root->right;
                delete root;
                return tp_node;
            }
        }

        if (root->val > val) {
            root->left = traversal(root->left, val);
        }

        if (root->val < val) {
            root->right = traversal(root->right, val);
        }
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        return traversal(root, key);
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
    vector<int> tree_nums = {5, 3, 6, 2, 4, null_num, 7};

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
    print_tree(so.deleteNode(root, 3));

    return 0;
}