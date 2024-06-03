/*************************
 * @file   : 3_reverse_link.cpp
 * @encode : UTF-8
 * @note   : 反转链表 https://leetcode.cn/problems/reverse-linked-list/
 * @date   : 2024/3/1 12
 *************************/

#include "iostream"
#include "vector"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *pre_node = head;
        ListNode *cur_node = head->next;

        while (cur_node != nullptr) {
            ListNode *tp = cur_node->next;

            cur_node->next = pre_node;
            pre_node = cur_node;

            cur_node = tp;
        }
        head->next = nullptr;
        return pre_node;
    }
};

int main() {
    ListNode *root = new ListNode();
    ListNode *cur_node = root;
    vector<int> data = {1, 2, 6, 3, 4, 5, 100};
    cur_node->val = data[0];
    for (int i = 1; i < data.size(); ++i) {
        ListNode *tp = new ListNode(data[i]);
        cur_node->next = tp;
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *new_head = so.reverseList(root);

    ListNode *loop_node = new_head;
    while (loop_node != nullptr) {
        cout << loop_node->val << " ";
        loop_node = loop_node->next;
    }
    cout << endl;

    return 0;
}