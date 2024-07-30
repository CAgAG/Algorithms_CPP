/*************************
 * @file   : 29_.cpp
 * @encode : UTF-8
 * @note   : 删除排序链表中的重复元素 II https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/16 19
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *new_head = new ListNode(-300);
        new_head->next = head;

        ListNode *pre_pre_node = new_head;
        ListNode *pre_node = new_head;
        ListNode *cur_node = head;

        while (cur_node != nullptr) {

            if (cur_node->val == pre_node->val) {
                while (cur_node != nullptr && cur_node->val == pre_node->val) {
                    cur_node = cur_node->next;
                }
                // 0(pre_pre_node), 1(pre_node), 1, cur_node(2)
                pre_pre_node->next = cur_node;
                pre_node = pre_pre_node;
                continue;
            }

            pre_pre_node = pre_node;
            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        return new_head->next;
    }
};

int main() {
    vector<int> nums = {1};
    ListNode *head = new ListNode(1);
    ListNode *cur_node = head;
    for (int i = 0; i < nums.size(); ++i) {
        cur_node->next = new ListNode(nums[i]);
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *ret = so.deleteDuplicates(head);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}