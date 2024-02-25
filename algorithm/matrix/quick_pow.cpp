/*************************
 * @file   : quick_pow.cpp
 * @encode : UTF-8
 * @note   : 实现快速幂取模
 * @date   : 2024/2/23 16
 *************************/
#include <iostream>

using namespace std;

long long quick_pow(long long base, long long exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent % 2 == 0) {
        long long temp = quick_pow(base, exponent / 2);
        return temp * temp;
    } else {
        return base * quick_pow(base, exponent - 1);
    }
}

long long quick_pow2(long long a, long long b, long long c) {
    /* 参数: a: 底数,  b: 指数, c: 模数
     * 返回值: (a^b) % c */
    long long ans = 1;
    a = a % c;  // 对 a 取模 c，确保 a 的值在 0 到 c-1 之间，这步是为了防止后续计算中的整数溢出。
    while (b) {
        // 用于判断一个整数是否为奇数或偶数, 整数 b 是偶数当且仅当 b & 1 的结果为 0; 是奇数当且仅当 b & 1 的结果为 1
        if (b & 1) {  // 二进制最后一位是 1
            ans = (ans * a) % c;
        }
        // 等同于 b = b / 2
        b >>= 1;  // 二进制右移一位
        a = (a * a) % c;
    }
    return ans;
}


int main() {
    long long base = 2, exponent = 5;
    cout << quick_pow(base, exponent) << endl;
    cout << quick_pow2(base, exponent, 3) << endl;
    return 0;
}
