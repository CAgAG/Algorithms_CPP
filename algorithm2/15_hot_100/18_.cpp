/*************************
 * @file   : 18_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/22 16
 *************************/

#include "iostream"
#include "vector"
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
    void revise_range_link(ListNode *head, ListNode *tail) {
        ListNode *pre_node = head;
        ListNode *cur_node = head->next;
        while (cur_node != tail) {
            ListNode *tp = cur_node->next;
            cur_node->next = pre_node;

            pre_node = cur_node;
            cur_node = tp;
        }
        cur_node->next = pre_node;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) {
            return head;
        }
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int link_length = 0;
        ListNode *ret;
        ListNode *cur_node = head;
        while (cur_node != nullptr) {
            link_length++;
            cur_node = cur_node->next;
        }

        ListNode *left_node = head;
        ListNode *right_node;
        ListNode *pre_range_tail_node = nullptr;
        cur_node = head;

        int cur_index = 1;
        while (cur_node != nullptr) {

            if (cur_index % k == 0) {
                ListNode *tp = cur_node->next;
                right_node = cur_node;
                // 翻转
                revise_range_link(left_node, right_node);
                left_node->next = tp;
                if (pre_range_tail_node != nullptr) {
                    pre_range_tail_node->next = right_node;
                }
                // 更新
                pre_range_tail_node = left_node;
                left_node = left_node->next;

                if (cur_index == k) {
                    ret = right_node;
                }
                // 当前节点更新
                cur_node = left_node;
                cur_index++;
                continue;
            }

            cur_node = cur_node->next;
            cur_index++;
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode *root = new ListNode(nums[0]);
    ListNode *cur_node = root;

    for (int i = 1; i < nums.size(); ++i) {
        cur_node->next = new ListNode(nums[i]);
        cur_node = cur_node->next;
    }

    Solution so;
    cur_node = so.reverseKGroup(root, k);
    while (cur_node != nullptr) {
        cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    cout << endl;
    return 0;
}