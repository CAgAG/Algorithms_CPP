/*************************
 * @file   : 12_bow.cpp
 * @encode : UTF-8
 * @note   : 用最少数量的箭引爆气球 https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
 * @date   : 2024/4/15 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
private:
    // 按左区间排序
    static bool cmp(const vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), cmp);

        int ret = 0;
        int left = points[0][0], right = points[0][1];  // 最多重叠的公共区间
        for (int i = 1; i < points.size(); ++i) {
            int left_p = points[i][0];
            int right_p = points[i][1];

            // 缩小区间
            if (left_p > left) {
                left = left_p;
            }
            if (right_p < right) {
                right = right_p;
            }

            // 跳出区间
            if (left > right) {
                ret++;
                // 重新计算 最多重叠的公共区间
                left = left_p;
                right = right_p;
            }
        }
        return ret + 1;
    }
};

int main() {
    vector<vector<int>> points = {
            {10, 16},
            {2,  8},
            {1,  6},
            {7,  12}
    };

    Solution so;
    cout << so.findMinArrowShots(points) << endl;
    return 0;
}