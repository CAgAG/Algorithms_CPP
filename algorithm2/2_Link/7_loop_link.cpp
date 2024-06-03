/*************************
 * @file   : 7_loop_link.cpp
 * @encode : UTF-8
 * @note   : 环形链表II https://leetcode.cn/problems/linked-list-cycle-ii/description/
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
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *slow_point = head;
        ListNode *fast_point = head;
        while (fast_point != nullptr && fast_point->next != nullptr) {
            slow_point = slow_point->next;
            fast_point = fast_point->next->next;

            if (slow_point == fast_point) {  // 有环
                ListNode *index1 = fast_point;  // 快慢指针相遇点
                ListNode *index2 = head;  // 头节点
                // 再找相遇的节点
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};


int main() {
    ListNode *root = new ListNode();
    ListNode *cur_node = root;
    vector<int> data = {3, 2, 0, -4};
    cur_node->val = data[0];
    for (int i = 1; i < data.size(); ++i) {
        ListNode *tp = new ListNode(data[i]);
        cur_node->next = tp;
        cur_node = cur_node->next;
    }

    ListNode *set_loop_node;
    cur_node = root;
    while (cur_node->next != nullptr) {
        if (cur_node->val == 2) {
            set_loop_node = cur_node;
        }
        cur_node = cur_node->next;
    }
    cur_node->next = set_loop_node;


    Solution so;
    ListNode *loop_node = so.detectCycle(root);

    cout << loop_node->val << endl;

    return 0;
}