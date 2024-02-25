/*************************
 * @file   : tx_search.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/15 17
 *************************/

/* 对于给定的一个长度为N的正整数数列Ai，现要将其分成M(M≤N)段, 要求每段连续，且每段和的最大值最小。
 * 解题: 最好的情况是 数列中的最大值单独一个区间
 *      那就可以设定 最大值为划分区间的依据之一
 */

#include "vector"
#include "iostream"

using namespace std;

int main() {
    int m = 3, max_range_sum = 0, final_ans = INT_MAX;

    int data_sum = 0, data_max = 0;
    vector<int> data = {
            4, 2, 4, 5, 1
    };

    for (int i = 0; i < data.size(); ++i) {
        data_sum += data[i];
        if (data[i] > data_max) {
            data_max = data[i];
        }
    }

    int left = data_max, right = data_sum;  // 区间和在最大值和全局和之间
    int mid, range_count, range_sum;
    while (left < right) {  // 二分搜索
        mid = (left + right) / 2;  // 搜索 题目要求的(最小)最大值
        range_count = 1;  // 默认自带一段, 因为是对数字之间划分的
        range_sum = 0;
        max_range_sum = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (range_sum + data[i] > mid) {
                if (range_sum > max_range_sum) {  // 最大区间值
                    max_range_sum = range_sum;
                }

                range_sum = data[i];
                range_count += 1;
            } else {
                range_sum += data[i];
            }
        }

        // 此处 mid +[-] 1, 是为了避免陷入死循环. 例如: left=3, right=4  ==> mid=3
        if (range_count < m) {  // 没达到划分次数
            right = mid - 1;  // 减小搜索值, 也相当于增加搜索次数
        } else if (range_count > m) {  // 超过划分次数
            left = mid + 1;  // 增大搜索值, 也相当于减少搜索次数
        } else {  // 等于划分次数
            right = mid - 1;  // 贪心: 减小搜索值
            if (max_range_sum < final_ans) {
                final_ans = max_range_sum;
            }
        }
    }
    cout << final_ans << endl;

    return 0;
}