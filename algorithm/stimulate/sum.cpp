/*************************
 * @file   : value.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/13 15
 *************************/

/* 已知Sn=1+1/2+1/3+..+1/n.给出一个整数k(1<=k<=15)计算出一个最小的n，使得Sn>k. */

#include "vector"
#include "iostream"

using namespace std;

int main() {
    const int k = 15;

    double Sn = 1.0;
    double n = 2.0;  // 分母
    while (true) {
        Sn += 1.0 / n;
        if (Sn > k) {
            cout << n << endl;
            cout << Sn << endl;
            return 0;
        }
        n += 1.0;
    }

    return 0;
}