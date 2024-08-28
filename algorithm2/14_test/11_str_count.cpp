/*************************
 * @file   : 11_str_count.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/10 10
 *************************/

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int ret = 0;
    vector<vector<bool>> visited;

    bool check(string s, int i, int j) {
        if (i == j) {
            return true;
        }
        if (j - i == 1) {
            return s[i] == s[j];
        }
        for (; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtrace(string s, int start_index) {
        if (start_index >= s.size()) {
            return;
        }

        for (int i = start_index; i < s.size(); ++i) {
            if (check(s, start_index, i) && !visited[start_index][i]) {
                visited[start_index][i] = true;
                ret++;
                backtrace(s, i + 1);
            }
        }
    }

    int countSubstrings(string s) {
        visited = vector<vector<bool>>(s.size() + 1, vector<bool>(s.size() + 1, false));
        backtrace(s, 0);
        return ret;
    }
};

int main() {
    string s = "abc";

    Solution so;
    cout << so.countSubstrings(s) << endl;
    return 0;
}