/*************************
 * @file   : 11_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/7/10 19
 *************************/

#include "iostream"
#include "vector"
#include "string"
#include "map"

using namespace std;

class Solution {
public:
    map<char, int> trans = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int romanToInt(string s) {
        int ret = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char cur_c = s[i];
            char next_c = 'z';
            if (i != n - 1) {
                next_c = s[i + 1];
            }


            if (cur_c == 'I' && (next_c == 'V' || next_c == 'X')) {
                if (next_c == 'V') {
                    ret += 4;
                } else {
                    ret += 9;
                }
                i++;
            } else if (cur_c == 'X' && (next_c == 'L' || next_c == 'C')) {
                if (next_c == 'L') {
                    ret += 40;
                } else {
                    ret += 90;
                }
                i++;
            } else if (cur_c == 'C' && (next_c == 'D' || next_c == 'M')) {
                if (next_c == 'D') {
                    ret += 400;
                } else {
                    ret += 900;
                }
                i++;
            } else {
                ret += trans[cur_c];
            }
        }
        return ret;
    }
};

int main() {
    string s = "LVIII";

    Solution so;
    cout << so.romanToInt(s) << endl;


    return 0;
}
