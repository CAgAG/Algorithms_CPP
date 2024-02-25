/*************************
 * @file   : bin_searrrch.cpp
 * @encode : UTF-8
 * @note   : 二分法
 * @darrte   : 2024/2/20 16
 *************************/

/* 解决的问题:
 * 具有单调性/连续性的问题二分查找
 * 最大最小问题/最小最大问题二分答案
 * 判断前缀的合法性二分前缀长度
 * 分数规划问题二分答案
 */

/* 有n个牛栏，分别位于X1,X2,.Xn。选m个放进牛，使得相邻牛之间的最小距离值最大。
 * m<=n<=1e 50<=Xi<=1e9
 * 解题: 二分最小距离值
 * */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 5;  // 牛栏的数量
const int M = 3;  // 共 3 头牛

int arr[N] = {1, 2, 8, 4, 9};  // 牛栏的位置
int judge(int k)  // 判断间距 k, 看能否能放置任意两头牛
{
    int pos = arr[0];
    int cnt = 1;  // 表示放进了 cnt头牛
    for (int i = 1; i < N; i++) {
        if (arr[i] - pos >= k) {  // 牛之间的距离大于等于 k即可放入牛栏
            pos = arr[i];
            cnt++;
        }
        if (cnt >= M)//牛的数量够了
            return 1;
    }
    return 0;
}


int main() {
    sort(arr,arr+N);  // 排序

    int ans = 0, mid = 0;
    int left = 0, right = N;

    while (left <= right) {
        mid = (left + right) / 2;
        if (judge(mid)) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}