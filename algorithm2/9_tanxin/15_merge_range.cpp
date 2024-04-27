/*************************
 * @file   : 15_merge_range.cpp
 * @encode : UTF-8
 * @note   : 合并区间 https://leetcode.cn/problems/merge-intervals/description/
 * @date   : 2024/4/22 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
private:
    // 左区间排序
    static bool cmp(const vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ret;
        if (intervals.size() == 0) {
            return ret;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> cur_range = intervals[i];
            vector<int> &last_range = ret[ret.size() - 1];
            // 合并区间
            if (cur_range[0] >= last_range[0] && cur_range[0] <= last_range[1]) {
                last_range[1] = max(last_range[1], cur_range[1]);
            } else {
                ret.push_back(cur_range);
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> points = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18}
    };

    Solution so;
    for (auto its: so.merge(points)) {
        for (auto it: its) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}