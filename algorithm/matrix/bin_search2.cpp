/*************************
 * @file   : bin_search.cpp
 * @encode : UTF-8
 * @note   : 二分法
 * @date   : 2024/2/20 16
 *************************/

/* 解决的问题:
 * 具有单调性/连续性的问题二分查找
 * 最大最小问题/最小最大问题二分答案
 * 判断前缀的合法性二分前缀长度
 * 分数规划问题二分答案
 */

/* 有n*m乘法表，将n*m个数从小到大依次排列，第K个数是多少?
 * 解题: 二分法求解。考虑对于给定的一个x, <=x的项一共有多少个
 * 在处理乘法表时，每一行都是一个等差数列, 对于第i行，其最大的数是i * m
 * 如果i * m小于x，则最大的数是i * m，否则最大的数是x）
 * 例如
 * 第一行 1 2 3 4  5  6  ... 1*1 2*1 3*1 4*1
 * 第二行 2 4 6 8  10 12 ... 1*2 2*2 3*2 4*2
 * 第三行 3 6 9 12 15 18 ... 1*3 2*3 3*3 4*3
 * ...
 * 这个乘法表是单调递增的，并且最后一个值(N*M)恰好就是所有数的数量
 * */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 2;
const int M = 3;
const int K = 4;

int judge(int x)
{
    int count = 0;
    for (int i = 1; i <= N; ++i) {  // 按行遍历
        // 计算第 i行中小于等于x的数的数量
        /* x / i 得到的是 x这个值最大是哪一行 */
        if (x / i < M) {
            count += x / i;
        } else {
            count += M;
        }
    }
    return count < K;
}


int main() {
    int ans = 0, mid = 0;
    int left = 0, right = M * N;

    while (left <= right) {
        mid = (left + right) / 2;
        if (judge(mid)) {
            left = mid + 1;
            ans = left;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}