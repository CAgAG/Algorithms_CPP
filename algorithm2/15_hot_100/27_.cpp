
/*************************
 * @file   : 22_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/23 11
 *************************/

#include "iostream"
#include "queue"
#include "algorithm"
#include "map"

using namespace std;

// 已知原数组 存在前缀和 = c, 目标和 k
// [1, 2, ..., a, ..., c] +
// 如果存在 a 使得 a + k = c  ==> c - k = a
// 那么 k 必在原数组中存在

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
    map<long long, int> mp;
    int ret = 0;

    void traver(TreeNode *root, int targetSum, long long cur_sum) {
        if (root == nullptr) {
            return;
        }

        cur_sum += root->val;
        if (mp.count(cur_sum - targetSum)) {
            ret += mp[cur_sum - targetSum];
        }

        mp[cur_sum]++;
        traver(root->left, targetSum, cur_sum);
        // 以下两步可以省略
        // mp[cur_sum]--;
        // mp[cur_sum]++;
        traver(root->right, targetSum, cur_sum);
        mp[cur_sum]--;
    }

    int pathSum(TreeNode *root, int targetSum) {
        mp[0] = 1;
        traver(root, targetSum, 0);
        return ret;
    }
};


int main() {
    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(-3);
    root->right->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    Solution so;
    cout << so.pathSum(root, 8) << endl;

    return 0;
}