/*************************
 * @file   : 6_split_str.cpp
 * @encode : UTF-8
 * @note   : 分割回文串 https://leetcode.cn/problems/palindrome-partitioning/description/
 * @date   : 2024/3/25 22
 *************************/

/* 回文 串是向前和向后读都相同的字符串。 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> ret;

public:
    // 判断回文串
    bool check(const string &s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtrace(const string &s, int start_index) {
        if (start_index >= s.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = start_index; i < s.size(); ++i) {
            if (check(s, start_index, i)) {
                string sub_s = s.substr(start_index, i - start_index + 1);
                path.push_back(sub_s);

                backtrace(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrace(s, 0);
        return ret;
    }
};

int main() {
    string s = "aab";

    Solution so;
    auto result = so.partition(s);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}
