/*************************
 * @file   : 31_.cpp
 * @encode : UTF-8
 * @note   : 填充每个节点的下一个右侧节点指针 II https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/16 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;


class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    queue<Node *> que;

    Node *connect(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }

        vector<vector<Node *>> nodes;
        que.push(root);
        while (!que.empty()) {
            int que_len = que.size();
            vector<Node *> q_nodes;

            for (int i = 0; i < que_len; ++i) {
                Node *cur_node = que.front();
                q_nodes.push_back(cur_node);
                que.pop();

                if (cur_node->left != nullptr) {
                    que.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    que.push(cur_node->right);
                }
            }

            nodes.push_back(q_nodes);
        }

        for (int i = 0; i < nodes.size(); ++i) {
            vector<Node *> level_nodes = nodes[i];
            if (level_nodes.size() >= 2) {
                for (int j = 0; j < level_nodes.size() - 1; ++j) {
                    level_nodes[j]->next = level_nodes[j + 1];
                }
            }
        }
        return root;
    }
};

int main() {
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution so;
    so.connect(root);

    return 0;
}


