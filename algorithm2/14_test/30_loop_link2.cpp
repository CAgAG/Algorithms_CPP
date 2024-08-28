/*************************
 * @file   : 30_loop_link2.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/14 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode *slow_p = head->next;
        ListNode *fast_p = head->next->next;

        while (slow_p != fast_p) {
            if (slow_p == nullptr || fast_p == nullptr || fast_p->next == nullptr) {
                return nullptr;
            }

            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
        }

        slow_p = head;
        while (slow_p != fast_p) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
        return slow_p;
    }
};

int main() {
    vector<int> nums = {3, 2, 0, -4};
    ListNode *head = new ListNode(nums[0]);
    ListNode *cur_node = head;

    ListNode *from_node, *to_node;

    for (int i = 1; i < nums.size(); ++i) {
        ListNode *new_node = new ListNode(nums[i]);

        if (new_node->val == -4) {
            from_node = new_node;
        }
        if (new_node->val == 2) {
            to_node = new_node;
        }

        cur_node->next = new_node;
        cur_node = cur_node->next;
    }

    from_node->next = to_node;

    Solution so;
    cout << so.detectCycle(head)->val << endl;

    return 0;
}