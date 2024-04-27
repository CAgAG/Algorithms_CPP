/*************************
 * @file   : 15_robber.cpp
 * @encode : UTF-8
 * @note   : 打家劫舍III https://leetcode.cn/problems/house-robber-iii/description/
 * @date   : 2024/4/24 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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
    // 设置状态值
    // 第一个值表示 拿, 第二值表示 不拿
    vector<int> rob_tree(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }

        vector<int> left = rob_tree(root->left);
        vector<int> right = rob_tree(root->right);

        // 拿2个子节点, 不拿当前节点
        // 选一个大的子节点, 或者不拿
        int ret_1 = max(left[0], left[1]) + max(right[0], right[1]);
        // 拿当前节点
        int ret_2 = root->val + left[1] + right[1];
        return {ret_2, ret_1};
    }

    int rob(TreeNode *root) {
        vector<int> ret = rob_tree(root);
        return max(ret[0], ret[1]);
    }

    // ==============================
    int rob_1(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob_1(root->left->left) + rob_1(root->left->right); // 跳过root->left，相当于不考虑左孩子了
        if (root->right) val1 += rob_1(root->right->left) + rob_1(root->right->right); // 跳过root->right，相当于不考虑右孩子了
        // 不偷父节点
        int val2 = rob_1(root->left) + rob_1(root->right); // 考虑root的左右孩子
        return max(val1, val2);
    }

    unordered_map<TreeNode *, int> umap; // 记录计算过的结果
    int rob_2(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        if (umap[root]) return umap[root]; // 如果umap里已经有记录则直接返回
        // 偷父节点
        int val1 = root->val;
        if (root->left) val1 += rob_2(root->left->left) + rob_2(root->left->right); // 跳过root->left
        if (root->right) val1 += rob_2(root->right->left) + rob_2(root->right->right); // 跳过root->right
        // 不偷父节点
        int val2 = rob_2(root->left) + rob_2(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2); // umap记录一下结果
        return max(val1, val2);
    }
};

void traversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    traversal(root->left);
    traversal(root->right);
}

int main() {
    int null_num = -1;
    vector<int> nums = {3, 4, 5, 1, 3, null_num, 1};

    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> que;
    que.push(root);

    for (int i = 0; i < nums.size(); ++i) {
        TreeNode *cur_node = que.front();
        que.pop();

        int left_node = 2 * i + 1;
        int right_node = 2 * i + 2;

        if (left_node < nums.size()) {
            TreeNode *left;
            if (nums[left_node] != null_num) {
                left = new TreeNode(nums[left_node]);
            } else {
                left = nullptr;
            }
            cur_node->left = left;
            que.push(left);
        }
        if (right_node < nums.size()) {
            TreeNode *right;
            if (nums[right_node] != null_num) {
                right = new TreeNode(nums[right_node]);
            } else {
                right = nullptr;
            }
            cur_node->right = right;
            que.push(right);
        }
    }

    traversal(root);
    cout << endl;

    Solution so;
    cout << so.rob(root) << endl;

    return 0;
}