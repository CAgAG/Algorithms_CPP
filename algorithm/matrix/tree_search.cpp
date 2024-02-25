/*************************
 * @file   : tree_search.cpp
 * @encode : UTF-8
 * @note   : 三分法 (Ternary Search)
 * @date   : 2024/2/20 17
 *************************/

/* 二分：单调区间
 * 三分：凸性函数
 */

#include <iostream>
#include <cmath>

using namespace std;

// 定义单峰函数，例如 f(x) = -x^2 + 4x
double f(double x) {
    return -x * x + 4 * x;
}

// 三分法求最大值
double ternarySearch(double left, double right, double eps) {
    double left_mid, right_mid;
    while (right - left > eps) {
        left_mid = left + (right - left) / 3;
        right_mid = right - (right - left) / 3;
        if (f(left_mid) < f(right_mid)) {
            left = left_mid;
        } else {
            right = right_mid;
        }
    }
    return (left + right) / 2;  // 返回近似最大值点
}

int main() {
    double left = 0.0;  // 定义搜索区间的左端点
    double right = 4.0;  // 定义搜索区间的右端点
    double eps = 1e-6;  // 定义搜索精度
    double xmax = ternarySearch(left, right, eps);  // 使用三分法求最大值点
    cout << "The maximum value is approximately at x = " << xmax << endl;
    cout << "The maximum value is approximately " << f(xmax) << endl;
    return 0;
}