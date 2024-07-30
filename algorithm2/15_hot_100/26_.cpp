
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
    TreeNode *traver(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        if (inorder.size() == 0) {
            return root;
        }

        int find_in_index = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == root->val) {
                find_in_index = i;
                break;
            }
        }

        vector<int> left_in(inorder.begin(), inorder.begin() + find_in_index);
        vector<int> right_in(inorder.begin() + find_in_index + 1, inorder.end());

        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + 1 + find_in_index); // 注意是【不包括当前节点】的分成【不重合】的【两个子数组】
        vector<int> right_pre(preorder.begin() + 1 + find_in_index, preorder.end());


        root->left = traver(left_pre, left_in);
        root->right = traver(right_pre, right_in);

        return root;
    }


    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = traver(preorder, inorder);
        return root;
    }
};

void tt(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << " ";
    tt(root->left);
    tt(root->right);
}

int main() {
    // vector<int> pre_nums = {3, 9, 20, 15, 7};
    // vector<int> in_nums = {9, 3, 15, 20, 7};
    vector<int> pre_nums = {1, 2, 3};
    vector<int> in_nums = {3, 2, 1};

    Solution so;
    TreeNode *cur_node = so.buildTree(pre_nums, in_nums);
    tt(cur_node);
    cout << endl;

    return 0;
}