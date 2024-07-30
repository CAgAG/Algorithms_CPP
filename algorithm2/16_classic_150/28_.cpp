/*************************
 * @file   : 27_.cpp
 * @encode : UTF-8
 * @note   : 分隔链表 https://leetcode.cn/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/15 11
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
    ListNode *partition(ListNode *head, int x) {

        ListNode *new_head = new ListNode(INT_MIN);
        new_head->next = head;

        ListNode *pre_node = new_head;
        ListNode *cur_node = head;
        ListNode *search_pre_node = nullptr;
        ListNode *search_node = nullptr;

        while (cur_node != nullptr) {
            if (cur_node->val >= x) {
                search_node = cur_node;
                while (search_node != nullptr && search_node->val >= x) {
                    search_pre_node = search_node;
                    search_node = search_node->next;
                }
                if (search_node == nullptr) {
                    break;
                }

                // search_node 连接
                search_pre_node->next = search_node->next;

                // cur_node 连接
                search_node->next = cur_node;
                pre_node->next = search_node;

                // pre_node 连接
                pre_node = search_node;
                continue;
            }

            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        return new_head->next;
    }
};


int main() {
    vector<int> nums = {4, 3, 2, 5, 2};
    ListNode *head = new ListNode(1);
    ListNode *cur_node = head;
    for (int i = 0; i < nums.size(); ++i) {
        cur_node->next = new ListNode(nums[i]);
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *ret = so.partition(head, 3);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}