/*************************
 * @file   : 2_.cpp
 * @encode : UTF-8
 * @note   : 回文数 https://leetcode.cn/problems/palindrome-number/description/
 * @date   : 2024/6/28 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    // 转为字符串
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<char> nums;
        while (x > 0) {
            nums.push_back('0' + (x % 10));
            x /= 10;
        }

        for (int i = 0, j = nums.size() - 1; i <= j; ++i, --j) {
            if (nums[i] != nums[j]) {
                return false;
            }
        }

        return true;
    }

    // ========================================================
    // 翻转一半数字，再对比原来的数字
    int reverse_num(int num) {  // num 只能是正数
        if (num < 10) {
            return num;
        }

        int ret = 0;
        while (num > 0) {
            ret *= 10;
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }


    bool isPalindrome2(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        // 1221: 12 | 21
        int left = x;

        int right = 0;
        int right_x = x;
        int right_i = 1;

        while (left >= right) {
            // 右边
            right += right_x % 10 * right_i;
            right_i *= 10;
            right_x /= 10;

            // 左边
            if (left == reverse_num(right)) {
                return true;
            }
            left /= 10;
            if (left == reverse_num(right)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    int x = 121;

    Solution so;
    cout << so.isPalindrome2(x) << endl;

    return 0;
}