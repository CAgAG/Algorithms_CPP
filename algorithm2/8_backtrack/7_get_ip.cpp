/*************************
 * @file   : 7_get_ip.cpp
 * @encode : UTF-8
 * @note   : 复原IP地址 https://leetcode.cn/problems/restore-ip-addresses/description/
 * @date   : 2024/3/25 22
 *************************/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<string> path;
    vector<string> ret;

public:
    // 左闭右闭 区间
    bool check(string &s, int start, int end) {
        // 前导 0
        if (end - start > 0 && s[start] == '0') {
            return false;
        }
        // 3位数
        if (end - start > 2) {
            return false;
        }

        for (int i = start; i <= end; ++i) {
            char cur_c = s[i];
            if (cur_c < '0' || cur_c > '9') {
                return false;
            }
        }
        // 0 ~ 255
        // cout << start << " " << end << endl;
        int trans_s = stoi(s.substr(start, end - start + 1));
        if (trans_s > 255) {
            return false;
        }

        return true;
    }

    void backtrace(string &s, int start_index, int add_point_count) {
        if (start_index >= s.size()) {
            return;
        }

        if (add_point_count == 3 && check(s, start_index, s.size() - 1)) {
            string ret_s = "";
            for (string ps: path) {
                ret_s += ps + ".";
            }
            ret_s += s.substr(start_index, s.size() - 1);
            ret.push_back(ret_s);
            return;
        }

        for (int i = start_index; i < s.size(); ++i) {
            if (check(s, start_index, i)) {
                path.push_back(s.substr(start_index, i - start_index + 1));
                backtrace(s, i + 1, add_point_count + 1);  // 点就是回溯的地方
                path.pop_back();
            }
        }

    }

    vector<string> restoreIpAddresses(string s) {
        backtrace(s, 0, 0);
        return ret;
    }
};

int main() {
    string s = "101023";

    Solution so;
    auto result = so.restoreIpAddresses(s);
    for (auto vecs: result) {
        cout << vecs << endl;
    }
    return 0;
}
