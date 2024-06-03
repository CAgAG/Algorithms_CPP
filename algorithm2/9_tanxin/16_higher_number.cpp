/*************************
 * @file   : 16_higher_number.cpp
 * @encode : UTF-8
 * @note   : 单调递增的数字 https://leetcode.cn/problems/monotone-increasing-digits/description/
 * @date   : 2024/4/22 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        // 从哪一位开始全部赋值为 9
        int flag = s.size();
        for (int i = s.size() - 1; i > 0; --i) {
            // 左边比右边大
            if (s[i - 1] > s[i]) {
                s[i - 1]--;  // 左边大的数 减一，减一是为了延续 ‘9’
                flag = i;  // 右边小的 标记为 9
            }
        }
        for (int i = flag; i < s.size(); ++i) {
            s[i] = '9';
        }
        return stoi(s);
    }
};

int main() {
    int n = 332;

    Solution so;
    cout << so.monotoneIncreasingDigits(n);
    return 0;
}