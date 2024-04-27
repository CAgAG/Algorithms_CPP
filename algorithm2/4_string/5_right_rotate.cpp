/*************************
 * @file   : 5_right_rotate.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/3/3 12
 *************************/

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    // 整体反转
    reverse(s.begin(), s.end());
    // 局部反转
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());

    cout << s <<endl;

    return 0;
}