/*************************
 * @file   : 1_input.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/4/11 09
 *************************/

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string"

using namespace std;

int main() {

    char get_c;
    while ((get_c = cin.get()) != '\n' && get_c != EOF) {
        cout << get_c << endl;
    }

    // ================
    string str;
    getline(cin, str);

    // ================
    char str2[20];
    cin.get(str2, 20);

    // ================
    const int rows = 3; // 行数
    const int cols = 4; // 列数
    int arr[rows][cols]; // 二维数组

    // 读取用户输入
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

    return 0;
}
