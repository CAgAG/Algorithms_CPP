/*************************
 * @file   : 8_extend4priority_queue.cpp
 * @encode : UTF-8
 * @note   : 要将优先队列 priority_queue<pair<int, int>> pque;改为对第一位从小到大排序
 * @date   : 2024/3/8 12
 *************************/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 对比函数
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pque(compare);

    // 添加元素到优先队列
    pque.push({3, 4});
    pque.push({1, 2});
    pque.push({5, 6});

    // 输出优先队列中的元素
    while (!pque.empty()) {
        cout << "(" << pque.top().first << ", " << pque.top().second << ")" << endl;
        pque.pop();
    }

    return 0;
}
