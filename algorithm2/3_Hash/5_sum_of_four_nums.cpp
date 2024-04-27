/*************************
 * @file   : 5_sum_of_four_nums.cpp
 * @encode : UTF-8
 * @note   : 四数相加II https://leetcode.cn/problems/4sum-ii/description/
 * @date   : 2024/3/2 11
 *************************/

#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;


class Solution {
public:
    // O(n^2)
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> map;  // 记录前 2个数组之和 以及出现的次数
        for (int it1: nums1) {
            for (int it2: nums2) {
                map[it1 + it2]++;
            }
        }

        int sum_count = 0;
        for (int it3: nums3) {
            for (int it4: nums4) {
                int target = 0 - (it3 + it4);  // 简单推导 n1 + n2 + n3 + n4 = 0
                if (map.find(target) != map.end()) {
                    sum_count += map[target];
                }
            }
        }
        return sum_count;
    }
};

int main() {
    vector<int> vec1 = {1, 2};
    vector<int> vec2 = {-2, -1};
    vector<int> vec3 = {-1, 2};
    vector<int> vec4 = {0, 2};


    Solution so;
    int ret = so.fourSumCount(vec1, vec2, vec3, vec4);
    cout << ret << endl;

    return 0;
}