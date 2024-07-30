/*************************
 * @file   : 3_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int move_point;

        for (move_point = 0; move_point < nums.size(); ++move_point) {
            if (nums[move_point] != 0) {
                continue;
            }

            for (int i = move_point; i < nums.size(); ++i) {
                if (nums[i] != 0) {
                    int tp = nums[move_point];
                    nums[move_point] = nums[i];
                    nums[i] = tp;
                    break;
                }

            }
        }


    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution so;
    so.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}