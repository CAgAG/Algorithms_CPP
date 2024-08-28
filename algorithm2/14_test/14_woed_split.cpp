/*************************
 * @file   : 14_woed_split.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/11 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    bool ret = false;
    vector<bool> memo;

    bool exist(string s, vector<string> &wd) {
        for (int i = 0; i < wd.size(); ++i) {
            if (wd[i] == s) {
                return true;
            }
        }
        return false;
    }

    bool backreace(string s, vector<string> &wd, int start_index) {  // 左闭右开
        if (start_index >= s.size()) {
            ret = true;
            return ret;
        }

        if (memo[start_index]) {
            return false;
        }

        for (int i = start_index; i < s.size(); ++i) {
            string sub_s = s.substr(start_index, (i - start_index) + 1);
            if (exist(sub_s, wd)) {
                if (backreace(s, wd, i + 1)) {
                    return ret;
                }
            }
        }

        memo[start_index] = true;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        ret = false;
        memo = vector<bool>(s.size(), false);
        // auto wordDict2 = set<string>(wordDict.begin(), wordDict.end());
        // wordDict = vector<string>(wordDict2.begin(), wordDict2.end());
        backreace(s, wordDict, 0);
        return ret;
    }
};

int main() {

    string s = "applepenapple";
    vector<string> wd = {"apple", "pen"};

    Solution so;

    cout << so.wordBreak(s, wd) << endl;


    return 0;
}