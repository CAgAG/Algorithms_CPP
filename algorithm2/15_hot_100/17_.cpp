/*************************
 * @file   : 14_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/22 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"
#include "queue"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *new_head = new ListNode(-1);
        ListNode *cur_node = new_head;

        bool next_plus_flag = false;
        while (l1 != nullptr && l2 != nullptr) {
            int ele = l1->val + l2->val;
            if (next_plus_flag) {
                ele += 1;
            }
            if (ele >= 10) {
                next_plus_flag = true;
                ele -= 10;
            } else {
                next_plus_flag = false;
            }

            l1 = l1->next;
            l2 = l2->next;
            cur_node->next = new ListNode(ele);
            cur_node = cur_node->next;
        }

        while (l1 != nullptr) {
            int ele = l1->val;
            if (next_plus_flag) {
                ele += 1;
            }
            if (ele >= 10) {
                next_plus_flag = true;
                ele -= 10;
            } else {
                next_plus_flag = false;
            }

            l1 = l1->next;
            cur_node->next = new ListNode(ele);
            cur_node = cur_node->next;
        }

        while (l2 != nullptr) {
            int ele = l2->val;
            if (next_plus_flag) {
                ele += 1;
            }
            if (ele >= 10) {
                next_plus_flag = true;
                ele -= 10;
            } else {
                next_plus_flag = false;
            }

            l2 = l2->next;
            cur_node->next = new ListNode(ele);
            cur_node = cur_node->next;
        }

        if (next_plus_flag) {
            cur_node->next = new ListNode(1);
        }

        return new_head->next;
    }
};

int main() {
    ListNode *root1 = new ListNode(2);
    root1->next = new ListNode(4);;
    root1->next->next = new ListNode(3);

    ListNode *root2 = new ListNode(5);
    root2->next = new ListNode(6);;
    root2->next->next = new ListNode(4);

    Solution so;
    ListNode *node = so.addTwoNumbers(root1, root2);
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}