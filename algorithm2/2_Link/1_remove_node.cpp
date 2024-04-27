/*************************
 * @file   : 1_remove_node.cpp
 * @encode : UTF-8
 * @note   : 移除链表元素 https://leetcode.cn/problems/remove-linked-list-elements/description/
 * @date   : 2024/3/1 10
 *************************/

#include "vector"
#include "iostream"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode new_root(0);  // 局部变量: 只用一次，函数结束后会自动销毁
        new_root.next = head;
        ListNode *cur_node = &new_root;

        while (cur_node->next != nullptr) {
            if (cur_node->next->val == val) {
                cur_node->next = cur_node->next->next;
            } else {
                cur_node = cur_node->next;
            }
        }
        return new_root.next;
    }
};

int main() {
    ListNode *root = new ListNode();
    ListNode *cur_node = root;
    vector<int> data = {1, 2, 6, 3, 4, 5, 6};
    cur_node->val = data[0];
    for (int i = 1; i < data.size(); ++i) {
        ListNode *tp = new ListNode(data[i]);
        cur_node->next = tp;
        cur_node = cur_node->next;
    }

    Solution so;
    ListNode *new_head = so.removeElements(root, 6);

    ListNode *loop_node = new_head;
    while (loop_node != nullptr) {
        cout << loop_node->val << " ";
        loop_node = loop_node->next;
    }
    cout << endl;

    return 0;
}