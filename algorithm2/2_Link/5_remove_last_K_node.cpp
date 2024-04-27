/*************************
 * @file   : 5_remove_last_K_node.cpp
 * @encode : UTF-8
 * @note   : 删除链表的倒数第N个节点 https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 * @date   : 2024/3/1 13
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode new_head(0);
        new_head.next = head;

        // 快慢指针
        ListNode *slow_point = &new_head;
        ListNode *fast_point = &new_head;
        // 快指针先前进 n 步
        while (n--) {
            fast_point = fast_point->next;
        }

        while (fast_point->next != nullptr) {
            fast_point = fast_point->next;
            slow_point = slow_point->next;
        }
        slow_point->next = slow_point->next->next;
        return new_head.next;
    }
};

int main() {
    ListNode *root = new ListNode();
    ListNode *cur_node = root;
    vector<int> data = {1, 2, 3, 4, 5};
    cur_node->val = data[0];
    for (int i = 1; i < data.size(); ++i) {
        ListNode *tp = new ListNode(data[i]);
        cur_node->next = tp;
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *new_head = so.removeNthFromEnd(root, 2);

    ListNode *loop_node = new_head;
    while (loop_node != nullptr) {
        cout << loop_node->val << " ";
        loop_node = loop_node->next;
    }
    cout << endl;

    return 0;
}