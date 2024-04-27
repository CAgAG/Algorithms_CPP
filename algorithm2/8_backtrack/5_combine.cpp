/*************************
 * @file   : 5_combine.cpp
 * @encode : UTF-8
 * @note   : 组合总和II https://leetcode.cn/problems/combination-sum-ii/description/
 * @date   : 2024/3/25 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ret;

public:
    // candidates 是已经排序过的
    void backtrace(vector<int> &candidates, int target, int cur_sum, int start_index, vector<bool> &used) {
        if (cur_sum > target) {
            return;
        }

        if (cur_sum == target) {
            ret.push_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size(); ++i) {
            // used[i - 1] == true， 说明 同一树枝 candidates[i - 1]使用过 (纵向)
            // used[i - 1] == false，说明 同一树层 candidates[i - 1]使用过 (横向)
            // 要对同一树层使用过的元素进行跳过
            if (i > 0
                && candidates[i] == candidates[i - 1]  // 重复元素
                && used[i - 1] == false) {  // 同一层
                continue;
            }

            path.push_back(candidates[i]);
            cur_sum += candidates[i];
            used[i] = true;
            backtrace(candidates, target, cur_sum, i + 1, used);
            path.pop_back();
            cur_sum -= candidates[i];
            used[i] = false;
        }

    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<bool> used(candidates.size(), false);
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());

        backtrace(candidates, target, 0, 0, used);
        return ret;
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution so;
    auto result = so.combinationSum2(candidates, target);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}