/*************************
 * @file   : 19_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/22 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;


class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        map<int, Node *> mp;  // 位置， 节点
        map<Node *, int> rmp;  // 原始节点， 位置

        // 提前创建
        Node *cur_node = head;
        int cur_index = 0;
        while (cur_node != nullptr) {
            mp[cur_index] = new Node(0);
            rmp[cur_node] = cur_index;

            cur_index++;
            cur_node = cur_node->next;
        }
        int tail_index = cur_index;
        mp[tail_index] = nullptr;

        // 创建链表
        cur_node = head;
        cur_index = 0;
        while (cur_node != nullptr) {

            Node *new_cur_node = mp[cur_index];
            new_cur_node->val = cur_node->val;
            new_cur_node->next = mp[cur_index + 1];

            if (cur_node->random != nullptr) {
                new_cur_node->random = mp[rmp[cur_node->random]];
            } else {
                new_cur_node->random = mp[tail_index];
            }

            cur_index++;
            cur_node = cur_node->next;
        }

        return mp[0];
    }
};

int main() {
    Node *node1 = new Node(3);
    Node *node2 = new Node(3);
    Node *node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    node2->random = node1;

    Solution so;
    Node *cur_node = so.copyRandomList(node1);

    return 0;
}