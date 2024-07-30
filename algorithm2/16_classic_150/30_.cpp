/*************************
 * @file   : 30_.cpp
 * @encode : UTF-8
 * @note   : 相同的树 https://leetcode.cn/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/16 19
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
    bool traver(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 != nullptr) {
            return false;
        } else if (root1 != nullptr && root2 == nullptr) {
            return false;
        } else if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if (root1->val != root2->val) {
            return false;
        }

        if (!traver(root1->left, root2->left)) {
            return false;
        }
        if (!traver(root1->right, root2->right)) {
            return false;
        }
        return true;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        return traver(p, q);
    }
};