/*************************
 * @file   : 6_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "unordered_map"

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() == 1) {
            return;
        }

        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution so;
    so.rotate(nums, 3);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}