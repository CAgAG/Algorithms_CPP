/*************************
 * @file   : 32_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/25 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    vector<string> ret;
    string path;
    vector<bool> used;

    bool check(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char cur_c = s[i];
            if (cur_c == '(') {
                st.push(cur_c);
            } else {
                if (st.empty()) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

    void traver(string nums) {
        if (path.size() == nums.size()) {
            if (check(path)) {
                ret.push_back(path);
            }
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);
            traver(nums);
            used[i] = false;
            path.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        string s = "";
        for (int i = 0; i < n; ++i) {
            s += "(";
        }
        for (int i = 0; i < n; ++i) {
            s += ")";
        }
        used = vector<bool>(s.size());
        traver(s);
        return ret;
    }
};

int main() {
    int n = 3;
    Solution so;

    for (auto sa: so.generateParenthesis(n)) {
        cout << sa << endl;
    }

    return 0;
}