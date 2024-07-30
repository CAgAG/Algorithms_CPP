/*************************
 * @file   : 24_.cpp
 * @encode : UTF-8
 * @note   : 插入区间 https://leetcode.cn/problems/insert-interval/submissions/546545154/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/14 15
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool in_range(vector<int> &range, int num) {
        int start = range[0];
        int end = range[1];
        if (num >= start && num <= end) {
            return true;
        }

        return false;
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {

        vector<vector<int>> ret;
        int n = intervals.size();
        if (n == 0) {
            ret.push_back(newInterval);
            return ret;
        }

        int insert_start = newInterval[0];
        int insert_end = newInterval[1];

        // left_i, range ...
        // 新区间在 所有区间的左边
        if (insert_end < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        // range, ..., left_i
        // 新区间在 所有区间的右边
        if (insert_start > intervals[n - 1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        // 新区间直接包括了 所有区间
        if (insert_start <= intervals[0][0] && insert_end >= intervals[n - 1][1]) {
            ret.push_back(newInterval);
            return ret;
        }
        // 新区间左不在 所有区间，右在 所有区间
        if (insert_start < intervals[0][0] && insert_end <= intervals[n - 1][1]) {
            int append_i = n;
            for (int i = 0; i < n; ++i) {
                vector<int> left_range = intervals[i];
                vector<int> right_range = {-1, -1};
                vector<int> sep_range = {-1, -1};
                if (i + 1 < n) {
                    right_range = intervals[i + 1];
                    sep_range = {left_range[1], right_range[0]};
                }

                if (in_range(left_range, insert_end)) {
                    ret.push_back({insert_start, left_range[1]});
                    append_i = i + 1;
                    break;
                } else if (in_range(right_range, insert_end)) {
                    ret.push_back({insert_start, right_range[1]});
                    append_i = i + 2;
                    break;
                } else if (in_range(sep_range, insert_end)) {
                    ret.push_back({insert_start, insert_end});
                    append_i = i + 1;
                    break;
                }
            }
            while (append_i < n) {
                ret.push_back(intervals[append_i]);
                append_i++;
            }
            return ret;
        }

        // 接下来的 新区间的左边一定在 所有区间里
        // 找到左区间
        int left_range_i = 0;  // 所在左区间的索引, 区间已加入 ret
        bool left_in_sep = false;
        for (int i = 0; i < n; ++i) {
            vector<int> left_range = intervals[i];
            vector<int> right_range = {-1, -1};
            vector<int> sep_range = {-1, -1};
            if (i + 1 < n) {
                right_range = intervals[i + 1];
                sep_range = {left_range[1], right_range[0]};
            }

            if (in_range(left_range, insert_start)) {
                ret.push_back(left_range);
                left_range_i = i;
                break;
            } else if (in_range(right_range, insert_start)) {
                ret.push_back(left_range);
                ret.push_back(right_range);
                left_range_i = i + 1;
                break;
            } else if (in_range(sep_range, insert_start)) {
                ret.push_back(left_range);
                left_range_i = i + 1;
                left_in_sep = true;
                break;
            }
            ret.push_back(left_range);
        }

        // 新区间右边 在所有区间之外(右边)
        if (insert_end > intervals[n - 1][1]) {
            if (left_in_sep) {
                ret.push_back({insert_start, insert_end});
            } else {
                vector<int> last_range = ret[ret.size() - 1];
                ret.pop_back();
                ret.push_back({last_range[0], insert_end});
            }
            return ret;
        }

        // 新区间右边 在所有区间
        // 找到右区间
        int right_range_i = 0;  // 所在左区间的索引, 区间已加入 ret
        bool right_in_sep = false;
        for (int i = max(0, left_range_i - 1); i < n; ++i) {
            vector<int> left_range = intervals[i];
            // n == 1?
            vector<int> right_range = {-1, -1};
            vector<int> sep_range = {-1, -1};
            if (i + 1 < n) {
                right_range = intervals[i + 1];
                sep_range = {left_range[1], right_range[0]};
            }

            if (in_range(left_range, insert_end)) {
                if (left_in_sep) {
                    ret.push_back({insert_start, left_range[1]});
                } else {
                    vector<int> last_range = ret[ret.size() - 1];
                    ret.pop_back();
                    ret.push_back({last_range[0], left_range[1]});
                }
                right_range_i = i;
                break;
            } else if (in_range(right_range, insert_end)) {
                if (left_in_sep) {
                    ret.push_back({insert_start, right_range[1]});
                } else {
                    vector<int> last_range = ret[ret.size() - 1];
                    ret.pop_back();
                    ret.push_back({last_range[0], right_range[1]});
                }
                right_range_i = i + 1;
                break;
            } else if (in_range(sep_range, insert_end)) {
                if (left_in_sep) {
                    ret.push_back({insert_start, insert_end});
                } else {
                    vector<int> last_range = ret[ret.size() - 1];
                    ret.pop_back();
                    ret.push_back({last_range[0], insert_end});
                }

                right_range_i = i + 1;
                right_in_sep = true;
                break;
            }

        }
        if (!right_in_sep) {
            right_range_i++;
        }
        while (right_range_i < n) {
            ret.push_back(intervals[right_range_i]);
            right_range_i++;
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> nums = {
            {1, 5}
    };
    vector<int> k = {0, 5};

    Solution so;
    for (auto cs: so.insert(nums, k)) {
        for (auto c: cs) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}