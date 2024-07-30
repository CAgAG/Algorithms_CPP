/*************************
 * @file   : 8_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        map<int, bool> exist;
        for (int i = 0; i < nums.size(); ++i) {
            exist[nums[i]] = true;
        }

        int max_num = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max_num) {
                max_num = nums[i];
            }
        }

        if (max_num <= 0) {
            return 1;
        }

        for (int i = 1; i <= max_num; ++i) {
            if (exist.find(i) != exist.end()) {
                continue;
            } else {
                return i;
            }
        }
        return max_num + 1;
    }
};

int main() {
    vector<int> nums = {3, 4, -1, 1};
    Solution so;
    cout << so.firstMissingPositive(nums) << endl;

    return 0;
}