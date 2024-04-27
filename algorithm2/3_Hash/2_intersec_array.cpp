/*************************
 * @file   : 2_intersec_array.cpp
 * @encode : UTF-8
 * @note   : 两个数组的交集 https://leetcode.cn/problems/intersection-of-two-arrays/description/
 * @date   : 2024/3/2 11
 *************************/

#include "iostream"
#include "unordered_map"
#include "unordered_set"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, bool> map;  // 统计数组是否出现过
        vector<int> ret;
        for (int it: nums1) {
            map[it] = true;
        }
        for (int it: nums2) {
            if (map.find(it) != map.end() && map[it]) {
                ret.push_back(it);
                map[it] = false;
            }
        }
        return ret;
    }

    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }

    //  O(m + n)
    vector<int> intersection3(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        int hash[1005] = {0}; // 默认数值为0
        for (int num : nums1) { // nums1中出现的字母在hash数组中做记录
            hash[num] = 1;
        }
        for (int num : nums2) { // nums2中出现话，result记录
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main() {
    vector<int> vec1 = {1, 2, 2, 1};
    vector<int> vec2 = {2, 2};

    Solution so;
    vector<int> ret = so.intersection(vec1, vec2);
    for (auto it: ret) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> ret2 = so.intersection2(vec1, vec2);
    for (auto it: ret2) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}