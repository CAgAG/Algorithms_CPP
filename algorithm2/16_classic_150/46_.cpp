/*************************
 * @file   : 46_.cpp
 * @encode : UTF-8
 * @note   : 位1的个数 https://leetcode.cn/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/22 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*
根据 与运算 定义，设二进制数字 n ，则有：

11 ==> 1011

若 n&1=0 ，则 n 二进制 最右一位 为 0 。
若 n&1=1 ，则 n 二进制 最右一位 为 1 。
 */

class Solution {
public:
    int hammingWeight(int n) {
        unsigned int ret = 0;
        while (n != 0) {
            ret += n & 1;
            n /= 2;
        }
        return ret;
    }
};

int main() {
    int n = 128;

    Solution so;
    cout << so.hammingWeight(n) << endl;
}