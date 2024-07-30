/*************************
 * @file   : 21_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/22 19
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        int n = lists.size();
        ListNode *new_head = new ListNode(-1);
        ListNode *cur_node = new_head;

        vector<ListNode *> lists_cur_node(lists.begin(), lists.end());

        while (1) {
            pair<int, int> diff = {INT_MAX, -1};  // 值，lists的位置
            bool all_end = true;
            for (int cur_l = 0; cur_l < n; ++cur_l) {
                if (lists_cur_node[cur_l] == nullptr) {
                    continue;
                }

                if (lists_cur_node[cur_l]->val < diff.first) {
                    diff = {lists_cur_node[cur_l]->val, cur_l};
                }
                all_end = false;
            }
            if (all_end) {
                break;
            }
            cur_node->next = lists_cur_node[diff.second];
            cur_node = cur_node->next;
            lists_cur_node[diff.second] = lists_cur_node[diff.second]->next;
        }

        return new_head->next;
    }
};

int main() {
    vector<ListNode *> lists(3);

    ListNode *link1 = new ListNode(1);
    link1->next = new ListNode(4);
    link1->next->next = new ListNode(5);

    ListNode *link2 = new ListNode(1);
    link2->next = new ListNode(3);
    link2->next->next = new ListNode(4);

    ListNode *link3 = new ListNode(2);
    link3->next = new ListNode(6);

    lists[0] = link1;
    lists[1] = link2;
    lists[2] = link3;

    Solution so;
    ListNode *cur_node = so.mergeKLists(lists);
    while (cur_node != nullptr) {
        cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    cout << endl;
    return 0;
}