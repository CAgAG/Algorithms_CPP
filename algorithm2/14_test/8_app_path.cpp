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
    vector<vector<int>> ret;
    vector<int> path;

    void traversal(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(path);
            return;
        }
        if (root->left != nullptr) {
            path.push_back(root->left->val);
            traversal(root->left);
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back(root->right->val);
            traversal(root->right);
            path.pop_back();
        }
    }

    vector<vector<int>> all_path(TreeNode *root) {
        path.push_back(root->val);
        traversal(root);
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

    for (auto its: so.all_path(root)) {
        for (auto it: its) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}