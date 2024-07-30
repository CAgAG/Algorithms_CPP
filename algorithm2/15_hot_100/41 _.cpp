/*************************
 * @file   : 41 _.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/26 10
 *************************/

#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

// 左边大顶堆，右边小顶堆，小的加左边，大的加右边
// [0, ..., mid_1, mid_2, ..., end]

class MedianFinder {
public:
    // 小顶堆, 保存比中间值大的部分
    priority_queue<int, vector<int>, greater<int>> que_right_min;
    // 大顶堆, 保存比中间值小的部分
    priority_queue<int, vector<int>, less<int>> que_left_max;

    MedianFinder() {

    }
    // 偶数 -> 奇数: que_left_max 更多
    // 奇数 -> 偶数: 一样多
    void addNum(int num) {
        // 偶数个元素
        if (que_right_min.size() == que_left_max.size()) {
            // 向右边插入
            que_right_min.push(num);
            // 右边, 再弹出来给左边, 保持平衡
            que_left_max.push(que_right_min.top());
            que_right_min.pop();
        } else {  // 有一个是奇数个元素, 且一定是 que_left_max; que_right_min 是平衡的
            que_left_max.push(num);
            // 给【右边加一个元素】, 保持左边平很
            que_right_min.push(que_left_max.top());
            que_left_max.pop();
        }
    }

    double findMedian() {
        if (que_left_max.size() == que_right_min.size()) {
            return (que_left_max.top() + que_right_min.top()) / 2.0;
        } else {
            return que_left_max.top();
        }

    }
};

int main() {

    return 0;
}