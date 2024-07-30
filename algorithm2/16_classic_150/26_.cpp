/*************************
 * @file   : 26_.cpp
 * @encode : UTF-8
 * @note   : 反转链表 II https://leetcode.cn/problems/reverse-linked-list-ii/submissions/546709397/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/15 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head->next == nullptr) {
            return head;
        }

        ListNode *new_head = new ListNode(-1);
        new_head->next = head;

        ListNode *pre_node = new_head;
        ListNode *left_node = head;
        int cur_i = 1;
        while (cur_i < left) {
            pre_node = left_node;
            left_node = left_node->next;
            cur_i++;
        }
        ListNode *right_node = left_node;
        while (cur_i < right) {
            right_node = right_node->next;
            cur_i++;
        }
        ListNode *tail_node = nullptr;
        if (right_node != nullptr) {
            tail_node = right_node->next;
        }

        // ..., pre_node, left_node, ..., right_node, tail_node, ...
        // 反转
        ListNode *node1 = left_node;
        ListNode *node2 = left_node->next;

        while (node2 != tail_node) {
            ListNode *tp = node2->next;
            node2->next = node1;

            node1 = node2;
            node2 = tp;
        }

        pre_node->next = right_node;
        left_node->next = tail_node;

        return new_head->next;

    }
};

int main() {

    ListNode *head = new ListNode(1);
    ListNode *cur_node = head;
    for (int i = 2; i < 6; ++i) {
        cur_node->next = new ListNode(i);
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *ret = so.reverseBetween(head, 2, 4);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}


