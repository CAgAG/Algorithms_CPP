/*************************
 * @file   : 5_.cpp
 * @encode : UTF-8
 * @note   : Pow(x, n) https://leetcode.cn/problems/powx-n/description/
 * @date   : 2024/6/29 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double ret = 1.0;
        while (n > 0) {
            if (n & 1) {
                // n的二进制当前位为1，则累乘当前的x
                ret *= x;
            }
            // x的2的指数次方幂
            x *= x;
            n >>= 1;
        }
        return ret;
    }

    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0 || x == 1) {
            return 1;
        }
        if (x == -1) {
            if (n % 2 == 1) {
                return -1;
            }
            return 1;
        }

        if (n < 0) {
            // n为最小整数，直接取反数值越界，等于INT_MAX + 1
            if (n == INT_MIN) {
                return 1 / (pow(x, INT_MAX) * x);
            }

            return 1 / pow(x, -n);
        } else {
            return pow(x, n);
        }


    }
};

int main() {
    double x = 2.0;
    int n = 10;

    Solution so;
    cout << so.myPow(x, n) << endl;
    return 0;
}