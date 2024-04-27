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
        int size_old = s.size();
        int count_num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                count_num++;
            }
        }
        s.resize(s.size() + 5 * count_num);
        int size_new = s.size();

        int i = size_old - 1, j = size_new - 1;
        // <-- i <-- j
        for (; i >= 0; --i, --j) {
            if (s[i] >= '0' && s[i] <= '9') {
                s[j] = 'r';
                s[j - 1] = 'e';
                s[j - 2] = 'b';
                s[j - 3] = 'm';
                s[j - 4] = 'u';
                s[j - 5] = 'n';
                j -= 5;
            } else {
                s[j] = s[i];
            }
        }

        cout << s << endl;
    }

    return 0;
}