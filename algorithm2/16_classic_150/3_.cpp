/*************************
 * @file   : 3_.cpp
 * @encode : UTF-8
 * @note   : 加一 https://leetcode.cn/problems/plus-one/description/
 * @date   : 2024/6/28 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    // 对当前位加一，并判断是否进一
    bool add(vector<int> &digits, int i) {
        if (digits[i] == 9) {
            digits[i] = 0;
            return true;
        } else {
            digits[i]++;
            return false;
        }
    }

    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (!add(digits, i)) {
                return digits;
            }
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    vector<int> nums = {1, 9, 9};

    Solution so;
    for (auto a: so.plusOne(nums)) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}