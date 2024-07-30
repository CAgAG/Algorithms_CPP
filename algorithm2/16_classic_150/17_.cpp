/*************************
 * @file   : 17_.cpp
 * @encode : UTF-8
 * @note   : 两数之和 II - 输入有序数组 https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/12 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {

        int n = numbers.size();
        for (int i = 0; i < n; ++i) {
            int index_1 = i;
            int cur_i1 = numbers[index_1];

            // 0, ..., i, left_i, ..., right_i(n)
            int left_i = i + 1;
            int right_i = n - 1;
            int find_num = target - cur_i1;
            while (left_i <= right_i) {
                int mid_i = (left_i + right_i) / 2;
                if (numbers[mid_i] == find_num) {
                    return {index_1 + 1, mid_i + 1};
                }

                if (numbers[mid_i] > find_num) {
                    right_i = mid_i - 1;
                } else {
                    left_i = mid_i + 1;
                }

            }
        }


        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int k = 9;

    Solution so;
    for (auto v: so.twoSum(nums, k)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}