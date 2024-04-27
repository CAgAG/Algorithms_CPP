/*************************
 * @file   : 11_full_combine.cpp
 * @encode : UTF-8
 * @note   : 全排列 https://leetcode.cn/problems/permutations/description/
 * @date   : 2024/3/26 11
 *************************/

#include "iostream"
#include "vector"
#include "set"
#include "unordered_set"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ret;
    vector<bool> used;

public:
    void backtrace(vector<int> &nums) {
        if (path.size() == nums.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == true) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrace(nums);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() == 1) {
            return {nums};
        }
        used = vector<bool>(nums.size(), false);
        backtrace(nums);
        return ret;
    }
};

int main() {
    vector<int> s = {1, 2, 3};

    Solution so;
    auto result = so.permute(s);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}