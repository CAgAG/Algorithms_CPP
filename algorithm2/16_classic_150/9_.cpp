/*************************
 * @file   : 9_.cpp
 * @encode : UTF-8
 * @note   : https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/7 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int start_i = 1;
        if (nums[0] == nums[1]) {
            start_i = 2;
        }
        int cur_i = start_i, cur_j = 1;

        for (int i = start_i; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                cur_j = i;

                nums[cur_i] = nums[cur_j];
                cur_i++;

                if (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                    cur_j = i + 1;

                    nums[cur_i] = nums[cur_j];
                    cur_i++;
                }
            }

        }
        return cur_i;
    }
};

int main() {

    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution so;
    int len = so.removeDuplicates(nums);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

