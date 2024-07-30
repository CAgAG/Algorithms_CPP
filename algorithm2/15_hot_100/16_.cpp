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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *l1 = list1;
        ListNode *l2 = list2;

        ListNode *new_head = new ListNode(-1);
        ListNode *cur_node = new_head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur_node->next = l1;
                l1 = l1->next;
            } else {
                cur_node->next = l2;
                l2 = l2->next;
            }
            cur_node = cur_node->next;
        }

        while (l1 != nullptr) {
            cur_node->next = l1;

            l1 = l1->next;
            cur_node = cur_node->next;
        }

        while (l2 != nullptr) {
            cur_node->next = l2;

            l2 = l2->next;
            cur_node = cur_node->next;
        }

        return new_head->next;
    }
};

int main() {
    ListNode *root1 = new ListNode(1);
    root1->next = new ListNode(2);;
    root1->next->next = new ListNode(4);

    ListNode *root2 = new ListNode(1);
    root2->next = new ListNode(3);;
    root2->next->next = new ListNode(4);

    Solution so;
    ListNode *node = so.mergeTwoLists(root1, root2);
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}