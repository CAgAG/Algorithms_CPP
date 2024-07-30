/*************************
 * @file   : 47_.cpp
 * @encode : UTF-8
 * @note   : 颠倒二进制位 https://leetcode.cn/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/22 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "cstdint"

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            // 从低位往高位枚举 n 的每一位，将其倒序添加到翻转结果 rev 中。
            rev += (n & 1) << (31 - i);
            n /= 2;
        }
        return rev;
    }
};