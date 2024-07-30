
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
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode *> que;
        vector<int> ret;
        que.push(root);

        while (!que.empty()) {
            int que_length = que.size();

            vector<int> level_nodes;
            for (int i = 0; i < que_length; ++i) {
                TreeNode *pop_node = que.front();
                que.pop();
                level_nodes.push_back(pop_node->val);

                if (pop_node->left != nullptr) {
                    que.push(pop_node->left);
                }
                if (pop_node->right != nullptr) {
                    que.push(pop_node->right);
                }
            }
            ret.push_back(level_nodes[level_nodes.size() - 1]);
        }
        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution so;
    for (auto s: so.rightSideView(root)) {
        cout << s << endl;
    }
    cout << endl;

    return 0;
}