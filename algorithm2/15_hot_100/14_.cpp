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
    ListNode *revise_link(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *pre_node = head;
        ListNode *cur_node = head->next;

        while (cur_node != nullptr) {
            ListNode *tp = cur_node->next;
            cur_node->next = pre_node;

            pre_node = cur_node;
            cur_node = tp;
        }
        head->next = nullptr;
        return pre_node;
    }

    bool isPalindrome(ListNode *head) {
        ListNode *s_node = head;
        ListNode *f_node = head;
        while (f_node != nullptr) {
            if (f_node->next == nullptr) {
                break;
            }
            f_node = f_node->next->next;
            s_node = s_node->next;
        }

        ListNode *newHead = revise_link(s_node);
        ListNode *cur_node = head;
        while (newHead != nullptr) {
            if (newHead->val != cur_node->val) {
                return false;
            }
            cur_node = cur_node->next;
            newHead = newHead->next;
        }
        return true;
    }
};

int main() {
    ListNode *root1 = new ListNode(1);

    root1->next = new ListNode(2);
    root1->next->next = new ListNode(2);
    root1->next->next->next = new ListNode(1);


    Solution so;
    cout << so.isPalindrome(root1) << endl;

    return 0;
}