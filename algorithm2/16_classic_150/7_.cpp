/*************************
 * @file   : 7_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/7/6 16
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        if (n == 0) {
            return;
        }

        int total_len = m + n;

        int tp_num1_i = total_len - 1;
        int nums1_i = 0;
        int nums2_i = 0;
        int first_swap_index = 0;

        while (1) {
            if (nums1_i < m && nums1[nums1_i] <= nums2[nums2_i]) {
                nums1_i++;
            } else {
                if (nums1_i < m) {
                    nums1[tp_num1_i] = nums1[nums1_i];
                    tp_num1_i--;
                    if (first_swap_index == 0) {
                        first_swap_index = nums1_i;
                    }
                }

                nums1[nums1_i] = nums2[nums2_i];
                nums1_i++;
                nums2_i++;
            }

            if (nums2_i >= n) {
                break;
            }
        }

        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution so;
    so.merge(nums1, m, nums2, n);

    for (auto a: nums1) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}