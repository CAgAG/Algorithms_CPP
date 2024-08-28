/*************************
 * @file   : 46_full_combine.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/19 12
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;
    vector<int> path;
    vector<bool> used;

    void backtrace(vector<int> &nums) {

        if (path.size() == nums.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);
            backtrace(nums);
            used[i] = false;
            path.pop_back();
        }

    }


    vector<vector<int>> permute(vector<int> &nums) {
        used = vector<bool>(nums.size(), false);
        backtrace(nums);
        return ret;
    }
};

int main() {

    vector<int> nums = {1, 2, 3};

    Solution so;
    for (auto as: so.permute(nums)) {
        for (auto a: as) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}