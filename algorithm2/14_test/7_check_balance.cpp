/*************************
 * @file   : 5_max_depth.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/5/12 11
 *************************/

#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool ret = true;

    int traversal(TreeNode *root, int depth) {
        if (root == nullptr) {
            return depth;
        }

        int left_f = traversal(root->left, depth + 1);
        int right_f = traversal(root->right, depth + 1);

        if (abs(left_f - right_f) > 1) {
            ret = false;
        }
        return max(left_f, right_f);
    }

    bool isBalanced(TreeNode *root) {
        traversal(root, 1);
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
    const int null_num = -1;

    vector<int> nums = {3, 9, 20, null_num, null_num, 15, 7};
    TreeNode *root = new TreeNode(nums[0]);
    queue<pair<TreeNode *, int>> que;
    que.push({root, 0});

    while (!que.empty()) {
        auto ele = que.front();
        TreeNode *cur_node = ele.first;
        int i = ele.second;
        que.pop();

        int left_index = 2 * i + 1;
        int right_index = 2 * i + 2;

        TreeNode *left = nullptr, *right = nullptr;
        if (left_index < nums.size() && nums[left_index] != null_num) {
            left = new TreeNode(nums[left_index]);
            que.push({left, left_index});
        }

        if (right_index < nums.size() && nums[right_index] != null_num) {
            right = new TreeNode(nums[right_index]);
            que.push({right, right_index});
        }
        cur_node->left = left;
        cur_node->right = right;
    }

    Solution so;

    cout << so.isBalanced(root) << endl;
    return 0;
}