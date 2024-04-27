/*************************
 * @file   : 2_stimu_stack_use_queue.cpp
 * @encode : UTF-8
 * @note   : 用队列实现栈 https://leetcode.cn/problems/implement-stack-using-queues/description/
 * @date   : 2024/3/7 22
 *************************/

#include "iostream"
#include "queue"

using namespace std;

class MyStack {
public:
    // que2 用于备份 que1 的元素
    queue<int> que1, que2;

    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int que1_size = que1.size();
        for (int i = 0; i < que1_size - 1; ++i) {
            que2.push(que1.front());
            que1.pop();
        }
        int ret = que1.front();
        que1.pop();

        while (que2.size() > 0) {
            que1.push(que2.front());
            que2.pop();
        }
        return ret;
    }

    int top() {
        int ret = this->pop();
        this->push(ret);
        return ret;
    }

    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack *obj = new MyStack();
    for (int i = 0; i < 10; ++i) {
        obj->push(i);
    }

    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->empty() << endl;
    return 0;
}