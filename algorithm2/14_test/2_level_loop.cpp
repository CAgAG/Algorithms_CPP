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
    vector<vector<int>> ret;

    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {{root->val}};
        }

        queue<TreeNode *> same_level;
        int cur_level = 0;
        same_level.push(root);
        while (!same_level.empty()) {
            int que_length = same_level.size();
            ret.push_back({});
            for (int i = 0; i < que_length; ++i) {
                TreeNode *pop_node = same_level.front();
                same_level.pop();

                ret[cur_level].push_back(pop_node->val);
                if (pop_node->left != nullptr) {
                    same_level.push(pop_node->left);
                }
                if (pop_node->right != nullptr) {
                    same_level.push(pop_node->right);
                }
            }
            cur_level++;
        }
        return ret;
    }
};

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

    for (auto its: so.levelOrder(root)) {
        for (auto it: its) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}