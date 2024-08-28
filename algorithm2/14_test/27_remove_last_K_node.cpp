/*************************
 * @file   : 27_remove_last_K_node.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/14 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;

        ListNode *pre_p = new_head;
        ListNode *cur_p = new_head->next;

        for (int i = 0; i < n; ++i) {
            cur_p = cur_p->next;
        }

        while (cur_p != nullptr) {
            pre_p = pre_p->next;
            cur_p = cur_p->next;
        }

        pre_p->next = pre_p->next->next;
        return new_head->next;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(nums[0]);
    ListNode *cur_node = head;

    for (int i = 1; i < nums.size(); ++i) {
        ListNode *new_node = new ListNode(nums[i]);
        cur_node->next = new_node;
        cur_node = cur_node->next;
    }

    Solution so;
    head = so.removeNthFromEnd(head, 2);
    cur_node = head;
    while (cur_node != nullptr) {
        cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    cout << endl;

    return 0;
}