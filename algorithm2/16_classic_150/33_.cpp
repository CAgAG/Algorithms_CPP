/*************************
 * @file   : 33_.cpp
 * @encode : UTF-8
 * @note   : 二叉搜索树迭代器 https://leetcode.cn/problems/binary-search-tree-iterator/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/17 10
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

class BSTIterator {
public:
    vector<int> nums;
    int g_i = 0;
    int len = 0;

    void traver(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        traver(root->left);
        nums.push_back(root->val);
        traver(root->right);
    }

    BSTIterator(TreeNode *root) {
        traver(root);
        this->len = nums.size();
    }

    int next() {
        if (this->g_i < this->len) {
            return nums[this->g_i++];
        }
        return INT_MIN;
    }

    bool hasNext() {
        if (this->g_i < this->len) {
            return true;
        }
        return false;
    }
};

int main() {
    TreeNode *root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator so(root);
    cout << so.next() << endl;

    return 0;
}