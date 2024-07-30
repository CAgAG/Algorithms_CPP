/*************************
 * @file   : 20_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/22 17
 *************************/

#include "iostream"
#include "vector"
#include "map"
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
    ListNode *merge(ListNode *list1, ListNode *list2) {
        if (list1 == list2) {
            return list1;
        }

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

    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode *node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }

        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength *= 2) {
            ListNode *prev = dummyHead, *curr = dummyHead->next;

            // 遍历链表
            while (curr != nullptr) {
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode *head2 = curr->next;
                curr->next = nullptr; // 此时的 curr是head1的尾节点

                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                // 保存下一次合并的头节点
                ListNode *next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }

                ListNode *merged = merge(head1, head2);
                prev->next = merged;  // 上一个合并的尾节点
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }

        }

        return dummyHead->next;
    }
};

int main() {
    vector<int> nums = {4, 2, 1, 3};
    ListNode *head = new ListNode(nums[0]);
    ListNode *cur_node = head;

    for (int i = 1; i < nums.size(); ++i) {
        cur_node->next = new ListNode(nums[i]);
        cur_node = cur_node->next;
    }

    Solution so;
    cur_node = so.sortList(head);
    while (cur_node != nullptr) {
        cout << cur_node->val << endl;
        cur_node = cur_node->next;
    }

    return 0;
}