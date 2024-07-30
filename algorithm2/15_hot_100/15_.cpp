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
    bool hasCycle(ListNode *head) {
        ListNode *sn = head;
        ListNode *fn = head;

        while (fn != nullptr) {
            sn = sn->next;
            if (fn->next == nullptr) {
                break;
            }
            fn = fn->next->next;

            if (sn == fn) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ListNode *root1 = new ListNode(3);

    ListNode *loop_node = new ListNode(2);
    root1->next = loop_node;
    root1->next->next = new ListNode(0);
    root1->next->next->next = new ListNode(4);
    root1->next->next->next->next = loop_node;


    Solution so;
    cout << so.hasCycle(root1) << endl;

    return 0;
}