/*************************
 * @file   : 5_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "unordered_map"

using namespace std;

class Solution {
public:
    unordered_map<char, int> target_map;

    bool check() {
        for (auto kv: target_map) {
            char key = kv.first;
            int value = kv.second;

            if (value < 0) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        for (int i = 0; i < n; ++i) {
            if (target_map.find(t[i]) != target_map.end()) {
                target_map[t[i]]--;
            } else {
                target_map[t[i]] = -1;
            }
        }

        int ret_len = INT_MAX;
        int ret_left_i = 0;

        int left_i = 0;
        int right_i = 0;
        while (right_i < m) {
            if (target_map.find(s[right_i]) == target_map.end()) {
                right_i++;
                continue;
            }

            target_map[s[right_i]]++;

            while (check()) {
                int cur_length = right_i - left_i;
                if (cur_length < ret_len) {
                    ret_len = cur_length;
                    ret_left_i = left_i;
                }
                // =============
                if (target_map.find(s[left_i]) != target_map.end()) {
                    target_map[s[left_i]]--;
                }
                left_i++;
            }
            right_i++;

        }
        if (ret_len != INT_MAX) {
            return s.substr(ret_left_i, ret_len + 1);
        } else {
            return "";
        }

    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution so;
    cout << so.minWindow(s, t) << endl;

    return 0;
}
