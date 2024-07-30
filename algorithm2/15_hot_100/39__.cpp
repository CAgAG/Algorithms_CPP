/*************************
 * @file   : 39_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/25 17
 *************************/

#include "iostream"
#include "vector"
#include "stack"
#include "queue"
#include "algorithm"

using namespace std;


class MinStack {
public:
    stack<int> norm_stack;
    stack<int> min_stack;

    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {
        norm_stack.push(val);

        if (val < min_stack.top()) {
            min_stack.push(val);
        } else {  // 如果插入值比 最小栈的顶元素大
            // 将最小值再压一个
            min_stack.push(min_stack.top());
        }
    }

    void pop() {
        norm_stack.pop();
        min_stack.pop();
    }

    int top() {
        return norm_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

int main() {
    MinStack ms = MinStack();
    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;

    return 0;
}