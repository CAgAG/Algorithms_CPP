/*************************
 * @file   : 7_revise_max_sum.cpp
 * @encode : UTF-8
 * @note   : K次取反后最大化的数组和 https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
 * @date   : 2024/4/13 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/* 两次贪心
 * 那么如果将负数都转变为正数了，K依然大于0，此时的问题是一个有序正整数序列，如何转变K次正负，让 数组和 达到最大。
 * 那么又是一个贪心：局部最优：只找数值最小的正整数进行反转，当前数值和可以达到最大
 */

/* 第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
 * 第二步：从前向后遍历，遇到负数将其变为正数，同时K--
 * 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
 * 第四步：求和
 */

class Solution {
private:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) { // 第三步, 奇数步
            A[A.size() - 1] *= -1;
        }
        int result = 0;
        for (int a: A) { // 第四步
            result += a;
        }
        return result;
    }
};

int main() {
    vector<int> num = {4, 2, 3};
    int k = 1;

    Solution so;
    cout << so.largestSumAfterKNegations(num, k) << endl;

    return 0;
}
