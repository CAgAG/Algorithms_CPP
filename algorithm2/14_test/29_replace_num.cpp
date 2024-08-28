/*************************
 * @file   : 29_replace_num.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/14 10
 *************************/

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

int main() {

    string str;

    while (getline(cin, str)) {
        int count_num = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                count_num++;
            }
        }

        int old_size = str.size();
        int new_size = str.size() + (count_num * 6);
        str.resize(new_size);

        int old_i = old_size - 1;
        int new_i = new_size - 1;

        while (old_i >= 0) {
            if (str[old_i] >= '0' && str[old_i] <= '9') {
                str[new_i] = 'r';
                str[new_i - 1] = 'e';
                str[new_i - 2] = 'b';
                str[new_i - 3] = 'm';
                str[new_i - 4] = 'u';
                str[new_i - 5] = 'n';
                new_i -= 6;
            } else {
                str[new_i] = str[old_i];
                new_i--;
            }
            old_i--;
        }
        str = str.substr(count_num, new_size);
        cout << str << endl;
    }

    return 0;
}