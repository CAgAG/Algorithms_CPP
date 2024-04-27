/*************************
 * @file   : 9_subset2.cpp
 * @encode : UTF-8
 * @note   : 子集II https://leetcode.cn/problems/subsets-ii/description/
 * @date   : 2024/3/26 10
 *************************/

#include "iostream"
#include "vector"
#include "unordered_set"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ret;
    vector<bool> used;

public:
    void backtrace(vector<int> &nums, int start_index) {
        ret.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }

        for (int i = start_index; i < nums.size(); ++i) {
            if (i > 0
                && nums[i] == nums[i - 1]
                && used[i - 1] == false) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrace(nums, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);
        backtrace(nums, 0);
        return ret;
    }

    // ==========================================
    // 不使用 used 数组的版本
    void backtrace2(vector<int> &nums, int start_index) {
        ret.push_back(path);
        if (start_index >= nums.size()) {
            return;
        }

        unordered_set<int> level_used;
        for (int i = start_index; i < nums.size(); ++i) {
            if (level_used.find(nums[i]) != level_used.end()) {
                continue;
            }

            level_used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrace2(nums, i + 1);
            path.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup2(vector<int> &nums) {
        // 可以排序就尽量排序
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtrace2(nums, 0);
        return ret;
    }
};

int main() {
    vector<int> s = {4, 4, 4, 1, 4};

    Solution so;
    auto result = so.subsetsWithDup(s);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }

    cout << "==========================" << endl;
    Solution so2;
    auto result2 = so2.subsetsWithDup2(s);
    for (auto vecs: result2) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}