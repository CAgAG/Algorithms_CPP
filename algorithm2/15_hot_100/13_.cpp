/*************************
 * @file   : 13_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/22 10
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len_a = 0;
        int len_b = 0;
        ListNode *cur_node = headA;
        while (cur_node != nullptr) {
            len_a++;
            cur_node = cur_node->next;
        }
        cur_node = headB;
        while (cur_node != nullptr) {
            len_b++;
            cur_node = cur_node->next;
        }

        ListNode *longer_node;
        if (len_a > len_b) {
            longer_node = headA;
            cur_node = headB;
        } else {
            longer_node = headB;
            cur_node = headA;
        }

        int diff = abs(len_a - len_b);
        while (diff != 0) {
            longer_node = longer_node->next;
            diff--;
        }

        while (longer_node != cur_node) {
            longer_node = longer_node->next;
            cur_node = cur_node->next;
        }
        return longer_node;
    }
};

int main() {
    ListNode *root1 = new ListNode(4);
    ListNode *root2 = new ListNode(5);

    root1->next = new ListNode(1);
    root2->next = new ListNode(6);
    root2->next->next = new ListNode(1);

    ListNode *insec_node = new ListNode(8);
    root1->next->next = insec_node;
    root2->next->next->next = insec_node;

    ListNode *insec_node2 = new ListNode(4);
    root1->next->next->next = insec_node2;
    root2->next->next->next->next = insec_node2;

    ListNode *insec_node3 = new ListNode(5);
    root1->next->next->next->next = insec_node3;
    root2->next->next->next->next->next = insec_node3;

    Solution so;
    cout << so.getIntersectionNode(root1, root2)->val << endl;

    return 0;
}