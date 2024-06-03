/*************************
 * @file   : 6_intersec_node.cpp
 * @encode : UTF-8
 * @note   : 链表相交 https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
 * @date   : 2024/3/1 13
 *************************/

#include "iostream"
#include "vector"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        // 对齐链表
        // 求出两个链表的长度，并求出两个链表长度的差值，然后让curA移动到，和curB 末尾对齐的位置
        int len_A = 1;
        int len_B = 1;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA->next != nullptr) {
            len_A++;
            curA = curA->next;
        }
        while (curB->next != nullptr) {
            len_B++;
            curB = curB->next;
        }

        // 定义: curA 比 curB 长
        int diff_num;  // 差值
        if (len_A > len_B) {
            curA = headA;
            curB = headB;
            diff_num = len_A - len_B;
        } else {
            curA = headB;
            curB = headA;
            diff_num = len_B - len_A;
        }
        // 长的先 走完差值
        while (diff_num--) {
            curA = curA->next;
        }

        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }

            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

int main() {
    ListNode *intersec_node = new ListNode(8);

    ListNode *root = new ListNode();
    ListNode *cur_node = root;
    vector<int> data = {4, 1, 8, 4, 5};
    cur_node->val = data[0];
    int intersec_index = 2;
    for (int i = 1; i < data.size(); ++i) {
        ListNode *tp;
        if (i == intersec_index) {
            tp = intersec_node;
        } else {
            tp = new ListNode(data[i]);
        }
        cur_node->next = tp;
        cur_node = cur_node->next;
    }

    ListNode *root2 = new ListNode();
    ListNode *cur_node2 = root2;
    vector<int> data2 = {5, 0, 1, 8, 4, 5};
    cur_node2->val = data2[0];
    int intersec_index2 = 3;
    for (int i = 1; i < data2.size(); ++i) {
        ListNode *tp;
        if (i == intersec_index2) {
            tp = intersec_node;
        } else {
            tp = new ListNode(data2[i]);
        }
        cur_node2->next = tp;
        cur_node2 = cur_node2->next;
    }

    Solution so;
    ListNode *get_intersec_node = so.getIntersectionNode(root, root2);

    cout << get_intersec_node->val << endl;

    return 0;
}