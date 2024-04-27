/*************************
 * @file   : 3_replace_nums.cpp
 * @encode : UTF-8
 * @note   : 替换数字 https://kamacoder.com/problempage.php?pid=1064
 * @date   : 2024/3/3 10
 *************************/

#include<iostream>

using namespace std;

int main() {
    // a1b2c3
    string s;
    while (cin >> s) {
        int count_num = 0; // 统计数字的个数
        int str_old_size = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count_num++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"number"之后的大小
        s.resize(s.size() + count_num * 5);  // 5是number的字符数
        int str_new_size = s.size();
        // j <-- number -- i
        // j指向旧长度的末尾; i指向新长度的末尾
        for (int i = str_new_size - 1, j = str_old_size - 1; i > j; --i, --j) {
            if (s[j] > '9' || s[j] < '0') {  // 不是数字
                s[i] = s[j];
            } else {
                s[i] = 'r';
                s[i - 1] = 'e';
                s[i - 2] = 'b';
                s[i - 3] = 'm';
                s[i - 4] = 'u';
                s[i - 5] = 'n';
                i -= 5;
            }
        }
        cout << s << endl;
    }

    return 0;
}