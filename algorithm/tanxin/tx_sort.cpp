/*************************
 * @file   : tx_sort.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/15 17
 *************************/

/* 有n堆果子，两两合并直到只剩一堆，每次合并消耗为两堆重量之和,求最小消耗
 * 贪心: 每次都合并最小的两个数
 ***/

#include "iostream"
#include "cstdio"
#include "queue"
#include "vector"

using namespace std;

// priority_queue<int> pq;  // 默认每次出最大的值 ==> top()
priority_queue<int, vector<int>, greater<int> > pq;  // 修改为每次出最小的值 ==> top()

int main() {
    int n = 3, ans = 0;

    for (int i = 0; i < n; ++i) {
        pq.push(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();
        ans += p1 + p2;
        pq.push(p1 + p2);
    }
    printf("%d\n", ans);

    return 0;
}