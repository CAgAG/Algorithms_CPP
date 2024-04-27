/*************************
 * @file   : 4_swap_neigbor_node.cpp
 * @encode : UTF-8
 * @note   : 两两交换链表中的节点 https://leetcode.cn/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode new_head(0);
        new_head.next = head;

        ListNode *left = &new_head;
        ListNode *mid_swap = head;
        ListNode *right_swap = head->next;

        while (right_swap != nullptr) {  // 死循环也可以
            // swap
            mid_swap->next = right_swap->next;
            right_swap->next = mid_swap;
            left->next = right_swap;  // 别忘了第一个节点的链接也要交换

            // update
            left = mid_swap;
            if (left->next == nullptr) {
                break;
            }
            mid_swap = mid_swap->next;
            right_swap = mid_swap->next;
        }

        return new_head.next;
    }
};

int main() {
    ListNode *root = new ListNode();
    ListNode *cur_node = root;
    vector<int> data = {1, 2, 3, 4};
    cur_node->val = data[0];
    for (int i = 1; i < data.size(); ++i) {
        ListNode *tp = new ListNode(data[i]);
        cur_node->next = tp;
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *new_head = so.swapPairs(root);

    ListNode *loop_node = new_head;
    while (loop_node != nullptr) {
        cout << loop_node->val << " ";
        loop_node = loop_node->next;
    }
    cout << endl;

    return 0;
}