/*************************
 * @file   : 48_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/27 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int left_i = 0;
        int right_i = nums.size() - 1;

        for (int i = 0; i <= right_i; ++i) {
            if (nums[i] == 0) {
                swap(nums[left_i], nums[i]);
                left_i++;
            }

            if (nums[i] == 2) {
                // 找到不为 2的位置
                while (i < right_i && nums[right_i] == 2) {
                    right_i--;
                }

                swap(nums[right_i], nums[i]);
                right_i--;
                // 有可能此处把 0再次送到了nums[i]的位置
                if (nums[i] == 0) {
                    swap(nums[left_i], nums[i]);
                    left_i++;
                }

            }

        }

    }
};

int main() {
    vector<int> nums = {2, 1, 2};

    Solution so;
    so.sortColors(nums);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}