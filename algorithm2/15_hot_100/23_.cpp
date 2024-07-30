/*************************
 * @file   : 22_.cpp
 * @encode : UTF-8
 * @note   : None
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