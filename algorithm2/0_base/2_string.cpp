/*************************
 * @file   : 2_string.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/4/11 09
 *************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// 根据字符分割
vector<string> split(string text, char delimiter) {
    vector<string> ret;
    string tp;
    stringstream is(text);
    while (getline(is, tp, delimiter)) {
        ret.push_back(tp);
    }
    return ret;
}

// 根据字符串分割
vector<string> split_str(string text, string delimiter) {
    vector<string> ret;

    int pos1 = 0;
    int pos2 = text.find(delimiter);
    while (string::npos != pos2) {
        ret.push_back(text.substr(pos1, pos2 - pos1));

        pos1 = pos2 + delimiter.size();
        pos2 = text.find(delimiter, pos1);
    }
    if (pos1 != text.length()) {
        ret.push_back(text.substr(pos1));
    }
    return ret;
}

int main() {
    string str = "   one, two,three,four   ";
    // 去除开头与结尾的多余字符
    string blanks("\f\v\r\t\n ");
    str.erase(0, str.find_first_not_of(blanks));
    str.erase(str.find_last_not_of(blanks) + 1);

    char delimiter = ',';

    vector<string> tokens = split(str, delimiter);

    for (const string &token: tokens) {
        cout << token << endl;
    }

    cout << "===================" << endl;

    vector<string> tokens2 = split_str(str, ",");

    for (const string &token: tokens2) {
        cout << token << endl;
    }

    return 0;
}