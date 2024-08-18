/*************************
 * @file   : 22_.cpp
 * @encode : UTF-8
 * @note   : 二叉搜索树中第K小的元素 https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked
 * @date   : 2024/6/23 11
 *************************/

#include "iostream"
#include "queue"
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
    priority_queue<int, vector<int>, greater<int>> pq;

    void traver(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        pq.push(root->val);
        traver(root->left);
        traver(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        traver(root);
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }

        return pq.top();
    }
};

int main() {
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root->left->right = new TreeNode(2);

    Solution so;
    cout << so.kthSmallest(root, 1) << endl;

    return 0;
}