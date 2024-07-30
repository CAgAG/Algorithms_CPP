/*************************
 * @file   : 14_.cpp
 * @encode : UTF-8
 * @note   : 最长公共前缀 https://leetcode.cn/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/11 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (n == 1) {
            return strs[0];
        }

        string ret = "";
        vector<int> indexs = vector<int>(n, 0);

        while (1) {
            char first_char = strs[0][indexs[0]++];
            for (int i = 1; i < n; ++i) {
                if (indexs[i] >= strs[i].size()) {
                    return ret;
                }

                if (first_char != strs[i][indexs[i]++]) {
                    return ret;
                }
            }
            ret += first_char;
        }

        return ret;
    }
};

int main() {
    vector<string> nums = {"flower", "flow", "flight"};
    Solution so;
    cout << so.longestCommonPrefix(nums) << endl;

    return 0;
}