/*************************
 * @file   : 8_subset.cpp
 * @encode : UTF-8
 * @note   : 子集 https://leetcode.cn/problems/subsets/description/
 * @date   : 2024/3/25 23
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
    void backtrace(vector<int> &nums, int start_index) {
        // 收集子集，要放在终止添加的上面，否则会漏掉自己
        ret.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }

        for (int i = start_index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        backtrace(nums, 0);
        return ret;
    }
};

int main() {
    vector<int> candidates = {1, 2, 3};

    Solution so;
    auto result = so.subsets(candidates);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}