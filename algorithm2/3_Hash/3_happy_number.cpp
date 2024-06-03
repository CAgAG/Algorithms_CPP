/*************************
 * @file   : 3_happy_number.cpp
 * @encode : UTF-8
 * @note   : 快乐数 https://leetcode.cn/problems/happy-number/description/
 * @date   : 2024/3/2 11
 *************************/
/* 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果 可以变为  1，那么这个数就是快乐数。*/

#include "iostream"
#include "unordered_map"
#include "unordered_set"
#include "vector"

using namespace std;

class Solution {
public:
    int compute_happy_number(int n) {
        int sum = 0;
        int low_n;
        while (n) {
            low_n = n % 10;
            sum += low_n * low_n;
            n /= 10;
        }
        return sum;
    }

    // O(logn)
    bool isHappy(int n) {
        unordered_set<int> sum_flag;
        int cur_sum = n;
        while (true) {
            cur_sum = compute_happy_number(cur_sum);
            if (cur_sum == 1) {
                return true;
            }

            if (sum_flag.find(cur_sum) != sum_flag.end()) {
                return false;
            }
            sum_flag.insert(cur_sum);  // 之前是否出现过了：出现了环
        }
    }
};


int main() {
    int n = 19;

    Solution so;
    cout << so.isHappy(n) << endl;

    return 0;
}