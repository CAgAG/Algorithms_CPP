/*************************
 * @file   : 27_.cpp
 * @encode : UTF-8
 * @note   : 旋转链表 https://leetcode.cn/problems/rotate-list/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/15 11
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int link_len = 1;
        ListNode *tail_node = head;
        while (tail_node->next != nullptr) {
            link_len++;
            tail_node = tail_node->next;
        }
        k %= link_len;
        if (k == 0) {
            return head;
        }

        ListNode *pre_node = nullptr;
        ListNode *last_k_node = head;
        ListNode *cur_node = head;
        for (int i = 0; i < k; ++i) {
            cur_node = cur_node->next;
        }
        while (cur_node != nullptr) {
            pre_node = last_k_node;
            last_k_node = last_k_node->next;
            cur_node = cur_node->next;
        }
        tail_node->next = head;
        pre_node->next = nullptr;

        return last_k_node;
    }
};


int main() {

    ListNode *head = new ListNode(1);
    ListNode *cur_node = head;
    for (int i = 2; i <= 5; ++i) {
        cur_node->next = new ListNode(i);
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *ret = so.rotateRight(head, 2);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}