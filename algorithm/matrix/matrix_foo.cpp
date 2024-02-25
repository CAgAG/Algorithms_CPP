/*************************
 * @file   : matrix_foo.cpp
 * @encode : UTF-8
 * @note   : 矩阵快速幂求解斐波那契数列
 * @date   : 2024/2/20 17
 *************************/

/* 求斐波那契数列的第n项
 * 矩阵快速幂求解斐波那契数列 */

#include <iostream>
#include <vector>

using namespace std;

// 定义矩阵结构体
struct Matrix {
    vector<vector<long long>> data;
    int rows, cols;

    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<long long>(c, 0)) {}

    // 矩阵乘法
    Matrix multiply(const Matrix &other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 矩阵快速幂
    Matrix power(long long n) const {
        Matrix result(rows, cols);
        // 创建单位矩阵
        for (int i = 0; i < rows; ++i) {
            result.data[i][i] = 1;
        }
        Matrix base(*this);
        while (n > 0) {
            if (n & 1) {  // 如果 n的二进制表示中的最低位是 1（即 n & 1为 true）
                result = result.multiply(base);
            }
            base = base.multiply(base);
            n >>= 1;  // 将 n右移一位（相当于除以2）
        }
        return result;
    }
};

// 计算斐波那契数列的第n项
long long fibonacci(long long n) {
    if (n <= 1) return n;

    Matrix base(2, 2);
    base.data[0][0] = 1;
    base.data[0][1] = 1;
    base.data[1][0] = 1;
    base.data[1][1] = 0;

    Matrix result = base.power(n - 1);
    return result.data[0][0];
}

int main() {
    long long n = 7;

    cout << "The " << n << "th Fibonacci graph is: " << fibonacci(n) << endl;

    return 0;
}