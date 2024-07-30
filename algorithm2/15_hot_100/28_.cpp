/*************************
 * @file   : 28_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/23 19
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
    int ret = INT_MIN;

    int traver(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_sum = traver(root->left);
        int right_sum = traver(root->right);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int cur_max = root->val;
        if (left_sum > 0) {
            cur_max += left_sum;
        }
        if (right_sum > 0) {
            cur_max += right_sum;
        }
        ret = max(ret, cur_max);

        // 返回节点的最大贡献值
        return root->val + max(0, max(left_sum, right_sum));  // 只来自一边 ==> 路径, 或者干脆不取
    }

    int maxPathSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        traver(root);
        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution so;
    cout << so.maxPathSum(root) << endl;

    return 0;
}
