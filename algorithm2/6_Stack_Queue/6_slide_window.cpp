/*************************
 * @file   : 6_slide_window.cpp
 * @encode : UTF-8
 * @note   : 滑动窗口最大值 https://leetcode.cn/problems/sliding-window-maximum/description/
 * @date   : 2024/3/8 09
 *************************/

#include "iostream"
#include "stack"
#include "deque"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

/* 单调队列
 * 其实队列没有必要维护窗口里的所有元素，只需要维护有可能成为窗口里最大值的元素就可以了 */
class MyQueue { //单调队列（从大到小）  ==> 队列本身(弹出和压入)就是数组的顺序
public:
    deque<int> que; // 使用deque来实现单调队列

    // 从左向右，旧到新(最后弹出的为新)。尝试从旧的数里删除
    // 队头弹出
    void pop(int value) { // 将 等于最大值的数弹出, 对应窗口 移除的数, 如果不是最大值就不操作
        if (!que.empty() && value == que.front()) {
            que.pop_front();
        }
    }

    // 尝试放到 “新“的位置
    void push(int value) {  // 维护 单调性, 对应窗口 加入的数
        // 将 小于 value的值全部弹出
        while (!que.empty() && value > que.back()) {
            que.pop_back();
        }
        que.push_back(value);
    }

    int front() {  // 返回最大值
        return que.front();
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue que;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }

        vector<int> ret;
        ret.push_back(que.front());
        int remove_num, append_num;
        for (int i = k; i < nums.size(); ++i) {
            remove_num = nums[i - k];
            append_num = nums[i];

            que.pop(remove_num);
            que.push(append_num);
            ret.push_back(que.front());
        }

        return ret;
    }
};

int main() {
    vector<int> tokens = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution so;

    for (auto a: so.maxSlidingWindow(tokens, k)) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}