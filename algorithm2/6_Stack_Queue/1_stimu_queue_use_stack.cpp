/*************************
 * @file   : 1_stimu_queue.cpp
 * @encode : UTF-8
 * @note   : 用栈实现队列 https://leetcode.cn/problems/implement-queue-using-stacks/description/
 * @date   : 2024/3/6 14
 *************************/

#include "iostream"
#include "stack"

using namespace std;


class MyQueue {
public:
    stack<int> STIn;
    stack<int> STOut;

    MyQueue() {

    }

    void push(int x) {
        STIn.push(x);
    }

    int pop() {
        if (STOut.empty()) {
            while (!STIn.empty()) {
                int popIn = STIn.top();
                STOut.push(popIn);
                STIn.pop();
            }
        }
        int ret = STOut.top();
        STOut.pop();
        return ret;
    }

    int peek() {
        int ret = this->pop();
        STOut.push(ret);
        return ret;
    }

    bool empty() {
        return STIn.empty() && STOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {

    MyQueue *obj = new MyQueue();
    for (int i = 0; i < 10; ++i) {
        obj->push(i);
    }

    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;

    return 0;
}