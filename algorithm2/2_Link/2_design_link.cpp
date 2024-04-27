/*************************
 * @file   : 2_design_link.cpp
 * @encode : UTF-8
 * @note   : 设计链表 https://leetcode.cn/problems/design-linked-list/description/
 * @date   : 2024/3/1 11
 *************************/

#include "iostream"
using namespace std;


class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        head = new LinkedNode(0);  // 虚拟头节点
        size = 0;
    }

    // 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1
    int get(int index) {
        if (index >= size || index < 0) {
            return -1;
        }

        LinkedNode *cur_node = head->next;
        int cur_index = 0;
        while (cur_index < index) {
            cur_node = cur_node->next;
            cur_index++;
        }
        return cur_node->val;
    }

    // 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点
    void addAtHead(int val) {
        /* 局部变量问题：new_head 是一个局部变量，它会在函数返回后被销毁。这意味着当你尝试访问它时（例如，在 head->next 指向它之后），
         * 你可能会遇到未定义的行为，因为那块内存可能已经被其他变量或函数使用。*/
        // LinkedNode new_head(val);
        LinkedNode *new_head = new LinkedNode(val); // 使用动态内存分配
        new_head->next = head->next;
        head->next = new_head;
        size++;
    }

    // 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    void addAtTail(int val) {
        LinkedNode *new_tail = new LinkedNode(val);
        LinkedNode *cur_node = head;

        while (cur_node->next != nullptr) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_tail;
        size++;
    }

    // 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
    // 如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。
    // 如果 index 比长度更大，该节点将 不会插入 到链表中。
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        // if (index == size) {
        //     addAtTail(val);
        //     return;
        // }

        LinkedNode *new_node= new LinkedNode(val);
        LinkedNode *pre_cur_node = head;
        // LinkedNode *cur_node = head->next;
        int cur_index = 0;
        while (cur_index < index) {
            pre_cur_node = pre_cur_node->next;
            // cur_node = cur_node->next;
            cur_index++;
        }
        new_node->next = pre_cur_node->next;
        pre_cur_node->next = new_node;
        size++;
    }

    // 如果下标有效，则删除链表中下标为 index 的节点。
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }

        int cur_index = 0;
        LinkedNode *pre_cur_node = head;
        while (cur_index < index) {
            pre_cur_node = pre_cur_node->next;
            cur_index++;
        }
        pre_cur_node->next = pre_cur_node->next->next;
        size--;
    }

    void print_link() {
        LinkedNode *cur_node = head->next;
        while (cur_node != nullptr) {
            cout << cur_node->val << " ";
            cur_node = cur_node->next;
        }
        cout << endl;
    }

private:
    LinkedNode *head;
    int size;
};

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(1);
    myLinkedList.addAtIndex(3, 0);

    myLinkedList.print_link();

    myLinkedList.deleteAtIndex(2);

    myLinkedList.print_link();

    myLinkedList.addAtHead(6);
    myLinkedList.addAtTail(4);

    myLinkedList.print_link();

    cout << myLinkedList.get(4) << endl;

    return 0;
}