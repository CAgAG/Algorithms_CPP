/*************************
 * @file   : 17_bin_tree_cameras.cpp
 * @encode : UTF-8
 * @note   : 监控二叉树 https://leetcode.cn/problems/binary-tree-cameras/description/
 * @date   : 2024/4/22 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
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

// 从下往上看，局部最优：让叶子节点的父节点安摄像头，所用摄像头最少
// 使用状态来模拟 每隔两个空节点放一个摄像头
class Solution {
private:
    int ret = 0;
    // 返回值是节点的状态
    /* 0：该节点无覆盖
     * 1：本节点有摄像头
     * 2：本节点有覆盖
     */
    int traversal(TreeNode *root) {
        if (root == nullptr) {
            return 2; // 表示已覆盖的状态
        }

        int left = traversal(root->left);
        int right = traversal(root->right);

        // 左右节点都有覆盖
        if (left == 2 && right == 2) {
            // 等父节点的父节点来放摄像头  ==> 隔两个空节点放一个摄像头
            return 0;
        }
        // 左右节点至少有一个无覆盖的情况
        if (left == 0 || right == 0) {
            // 摄像头只能放在无覆盖的情况
            ret++;
            return 1;
        }
        // 左右节点至少有一个有摄像头
        if (left == 1 || right == 1) return 2;

        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }

public:
    int minCameraCover(TreeNode *root) {
        if (traversal(root) == 0) { // root(根节点) 无覆盖
            ret++;
        }
        return ret;
    }
};

int main() {
    const int null_num = -100;  // 定义为 null 节点的值
    vector<int> tree_nums = {0, 0, null_num, 0, 0};

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
    cout << so.minCameraCover(root) << endl;

    return 0;
}