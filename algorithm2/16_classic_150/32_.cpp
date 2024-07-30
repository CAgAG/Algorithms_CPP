/*************************
 * @file   : 32_.cpp
 * @encode : UTF-8
 * @note   : 求根节点到叶节点数字之和 https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/17 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


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
    void traversal2(TreeNode *root, vector<int> &path, vector<vector<int>> &paths) {
        path.push_back(root->val);
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(vector<int>(path.begin(), path.end()));
            return;
        }

        if (root->left != nullptr) {
            traversal2(root->left, path, paths);
            path.pop_back();
        }
        if (root->right != nullptr) {
            traversal2(root->right, path, paths);
            path.pop_back();
        }
    }


    int sumNumbers(TreeNode *root) {
        vector<int> path;
        vector<vector<int>> ret;
        traversal2(root, path, ret);

        int rets = 0;

        for (int i = 0; i < ret.size(); ++i) {
            int ele_num = 0;
            long num = 1;
            for (int j = ret[i].size() - 1; j >= 0; --j) {
                ele_num += ret[i][j] * num;
                num *= 10;
            }
            rets += ele_num;
        }

        return rets;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(9);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    Solution so;
    cout << so.sumNumbers(root) << endl;

    return 0;
}