/*************************
 * @file   : 4_combine.cpp
 * @encode : UTF-8
 * @note   : 组合总和 https://leetcode.cn/problems/combination-sum/description/
 * @date   : 2024/3/25 15
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
    void backtrace(vector<int> &candidates, int target, int start_index, int cur_sum) {
        if (cur_sum > target) {
            return;
        }
        if (cur_sum == target) {
            ret.push_back(path);
            return;
        }


        for (int i = start_index; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            cur_sum += candidates[i];
            backtrace(candidates, target, i, cur_sum);
            path.pop_back();
            cur_sum -= candidates[i];
        }
    }


    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrace(candidates, target, 0, 0);
        return ret;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution so;
    auto result = so.combinationSum(candidates, target);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }


    return 0;
}