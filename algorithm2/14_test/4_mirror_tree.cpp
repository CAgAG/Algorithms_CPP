/*************************
 * @file   : 2_level_loop.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/5/12 10
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
    TreeNode *ret;

    bool traversal(TreeNode *root) {

        queue<TreeNode *> que_left;
        queue<TreeNode *> que_right;

        que_left.push(root->left);
        que_right.push(root->right);

        while (!que_left.empty() && !que_right.empty()) {
            TreeNode *left_c = que_left.front();
            que_left.pop();
            TreeNode *right_c = que_right.front();
            que_right.pop();

            if (left_c == nullptr && right_c != nullptr) {
                return false;
            }
            if (left_c != nullptr && right_c == nullptr) {
                return false;
            }
            if (left_c == nullptr && right_c == nullptr) {
                continue;
            }
            if (left_c->val != right_c->val) {
                return false;
            }

            que_left.push(left_c->left);
            que_left.push(left_c->right);

            que_right.push(right_c->right);
            que_right.push(right_c->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return false;
        }
        return traversal(root);
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

    cout << so.is_mirror_tree(root) << endl;
    return 0;
}