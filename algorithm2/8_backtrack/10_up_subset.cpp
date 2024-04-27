/*************************
 * @file   : 10_up_subset.cpp
 * @encode : UTF-8
 * @note   : 递增子序列 https://leetcode.cn/problems/non-decreasing-subsequences/description/
 * @date   : 2024/3/26 10
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
    void backtrace(vector<int> &nums, int start_index) {
        if (path.size() >= 2) {
            ret.push_back(path);
        }
        if (start_index >= nums.size()) {
            return;
        }

        for (int i = start_index; i < nums.size(); ++i) {
            if (i > 0
                && nums[i] == nums[i - 1]
                && used[i - 1] == false) {
                continue;
            }
            if (!path.empty() && nums[i] < path[path.size() - 1]) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrace(nums, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        used = vector<bool>(nums.size(), false);
        backtrace(nums, 0);
        set<vector<int>> s_ret(ret.begin(), ret.end());
        return vector<vector<int>>(s_ret.begin(), s_ret.end());
    }

    // ======================================================
    void backtrace2(vector<int> &nums, int start_index) {
        if (path.size() >= 2) {
            ret.push_back(path);
        }
        if (start_index >= nums.size()) {
            return;
        }

        // 记录本层元素是否重复使用，新的一层 level_used 都会重新定义（清空），所以要知道 level_used 只负责本层！
        unordered_set<int> level_used;
        for (int i = start_index; i < nums.size(); ++i) {
            if (level_used.find(nums[i]) != level_used.end()) {  // 找到本层重复元素
                continue;
            }
            if (!path.empty() && nums[i] < path[path.size() - 1]) {
                continue;
            }

            level_used.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences2(vector<int> &nums) {
        used = vector<bool>(nums.size(), false);
        backtrace2(nums, 0);
        return ret;
    }
};

int main() {
    vector<int> s = {1, 2, 3, 1, 1, 1, 1, 1};

    Solution so;
    auto result = so.findSubsequences(s);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }

    cout << "========================" << endl;
    Solution so2;
    auto result2 = so2.findSubsequences2(s);
    for (auto vecs: result2) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}