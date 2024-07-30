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

    stack<int> copy_stack;
    stack<int> min_stack;

    MinStack() {

    }

    void clear_copy() {
        while (!copy_stack.empty()) {
            copy_stack.pop();
        }
    }

    void push(int val) {
        norm_stack.push(val);

        clear_copy();
        if (!min_stack.empty()) {
            while (!min_stack.empty() && min_stack.top() < val) {
                copy_stack.push(min_stack.top());
                min_stack.pop();
            }
            min_stack.push(val);
            while (!copy_stack.empty()) {
                min_stack.push(copy_stack.top());
                copy_stack.pop();
            }
        } else {
            min_stack.push(val);
        }
    }

    void pop() {
        int pop_val = norm_stack.top();
        norm_stack.pop();

        clear_copy();
        while (min_stack.top() != pop_val) {
            copy_stack.push(min_stack.top());
            min_stack.pop();
        }
        min_stack.pop();
        while (!copy_stack.empty()) {
            min_stack.push(copy_stack.top());
            copy_stack.pop();
        }
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