/*************************
 * @file   : 34_.cpp
 * @encode : UTF-8
 * @note   : 二叉树的层平均值 https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/17 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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
    queue<TreeNode *> que;

    vector<double> averageOfLevels(TreeNode *root) {

        que.push(root);
        vector<double> ret;
        while (!que.empty()) {
            int q_len = que.size();

            double level_sum = 0;
            for (int i = 0; i < q_len; ++i) {
                TreeNode *node= que.front();
                que.pop();

                level_sum += node->val;

                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            ret.push_back(level_sum / q_len);
        }

        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(9);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    Solution so;
    for (auto c: so.averageOfLevels(root)) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}