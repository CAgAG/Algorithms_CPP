/*************************
 * @file   : 13_remove_range.cpp
 * @encode : UTF-8
 * @note   : 无重叠区间 https://leetcode.cn/problems/non-overlapping-intervals/description/
 * @date   : 2024/4/18 12
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; // 注意这里从0开始，因为是记录重叠区间
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) { // 无重叠的情况
                end = intervals[i][1];
            } else { // 重叠情况
                end = min(end, intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> nums = {{1, 2},
                                {2, 3},
                                {3, 4},
                                {1, 3}};

    Solution so;
    cout << so.eraseOverlapIntervals(nums) << endl;

    return 0;
}