/*************************
 * @file   : 48_.cpp
 * @encode : UTF-8
 * @note   : 数字范围按位与 https://leetcode.cn/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/22 22
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*
既然题目都提到按位与了，那先来回忆一下按位与的运算规则：

0 & 0 = 0
0 & 1 = 1 & 0 = 0
1 & 1 = 1
总结一下就是，两个位的值都为 1，按位与的结果才为 1，否则必为 0。

 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mask = 1 << 30; // 最高位开始
        int ret = 0;
        while (mask > 0) {
            int left_b = left & mask;
            int right_b = right & mask;

            // 寻找相同前缀
            if (left_b != right_b) {
                break;
            }

            // 最长相同前缀
            ret |= left_b;
            mask >>= 1;  // 右移一位
        }
        return ret;
    }
};

int main() {


    return 0;
}
