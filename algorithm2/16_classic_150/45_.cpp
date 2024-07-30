/*************************
 * @file   : 45_.cpp
 * @encode : UTF-8
 * @note   : 二进制求和 https://leetcode.cn/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/22 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";

        int m = a.size();
        int n = b.size();
        while (m > n) {
            b = '0' + b;
            n++;
        }
        while (m < n) {
            a = '0' + a;
            m++;
        }

        int cur_a_i = m - 1;
        int cur_b_i = n - 1;
        bool pre_add = false;
        while (cur_a_i >= 0 || cur_b_i >= 0) {
            int end_a_c = a[cur_a_i] - '0';
            int end_b_c = b[cur_b_i] - '0';

            int end_sum = end_a_c + end_b_c;
            if (pre_add) {
                end_sum += 1;
            }

            if (end_sum >= 2) {
                pre_add = true;
            } else {
                pre_add= false;
            }
            end_sum %= 2;
            ret = char(end_sum + '0') + ret;

            cur_a_i--;
            cur_b_i--;
        }
        if (pre_add) {
            ret = '1' + ret;
        }
        return ret;
    }
};

int main() {
    string s = "1010";
    string k = "1011";

    Solution so;
    cout << so.addBinary(s, k) << endl;

    return 0;
}