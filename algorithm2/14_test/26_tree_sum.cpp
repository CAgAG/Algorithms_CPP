/*************************
 * @file   : 26_tree_sum.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/14 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        // ... a, ... b, ... c, ....
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int a = nums[i];
            set<int> b_set;

            for (int j = i + 1; j < n; ++j) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
                    continue;
                }

                int c = nums[j];
                // a + b + c = 0
                // ===> b = 0 - (a + b)
                int b = 0 - (a + c);

                if (b_set.find(b) != b_set.end()) {  // 可以找到
                    ret.push_back({a, b, c});
                    b_set.erase(b);
                } else {
                    b_set.insert(c);
                }
            }

        }
        return ret;
    }
};

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution so;
    for (auto rs: so.threeSum(nums)) {
        for (auto r: rs) {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}