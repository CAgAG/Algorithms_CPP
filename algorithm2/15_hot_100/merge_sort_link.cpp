/*************************
 * @file   : merge_sort_link.cpp
 * @encode : UTF-8
 * @note   : https://leetcode.cn/problems/7WHec2/
 * @date   : 2024/6/23 23
 *************************/

#include "iostream"
#include "algorithm"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *link1, ListNode *link2) {
    ListNode *new_head = new ListNode(-1);
    ListNode *cur_node = new_head;

    ListNode *l1 = link1;
    ListNode *l2 = link2;
    while (1) {
        if (l1 == nullptr && l2 == nullptr) {
            break;
        } else if (l1 != nullptr && l2 == nullptr) {
            cur_node->next = l1;
            l1 = l1->next;
        } else if (l1 == nullptr && l2 != nullptr) {
            cur_node->next = l2;
            l2 = l2->next;
        } else {
            if (l1->val < l2->val) {
                cur_node->next = l1;
                l1 = l1->next;
            } else {
                cur_node->next = l2;
                l2 = l2->next;
            }
        }
        cur_node = cur_node->next;
    }
    return new_head->next;
}

ListNode *merge_sort(ListNode *link) {
    int link_length = 0;
    ListNode *cur_node = link;
    while (cur_node != nullptr) {
        link_length++;
        cur_node = cur_node->next;
    }

    ListNode* new_head = new ListNode(-1, link);
    // 区间节点树
    int node_l = 1;
    for (; node_l < link_length; node_l *= 2) {




    }

}


// ====================================
class Solution {
public:
    ListNode *sortList(ListNode *head) {

    }
};

int main() {
    ListNode *head = new ListNode(4);

    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution so;
    ListNode *cur_node = so.sortList(head);
    while (cur_node != nullptr) {
        cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    cout << endl;
    return 0;
}