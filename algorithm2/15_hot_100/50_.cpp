/*************************
 * @file   : 50_.cpp
 * @encode : UTF-8
 * @note   : 下一个排列 https://leetcode.cn/problems/next-permutation/description/?envType=study-plan-v2&envId=top-100-liked
 * @date   : 2024/6/27 20
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*
 * 我们希望下一个数 比当前数大，这样才满足 “下一个排列” 的定义。因此只需要 将后面的「大数」与前面的「小数」交换，就能得到一个更大的数。比如 123456，将 5 和 6 交换就能得到一个更大的数 123465。
 * 我们还希望下一个数 增加的幅度尽可能的小，这样才满足“下一个排列与当前排列紧邻“的要求。为了满足这个要求，我们需要：
 *      a: 在 尽可能靠右的低位 进行交换，需要 从后向前 查找
 *      b: 将一个 尽可能小的「大数」 与前面的「小数」交换。比如 123465，下一个排列应该把 5 和 4 交换而不是把 6 和 4 交换
 *      c: 将「大数」换到前面后，需要将「大数」后面的所有数 重置为升序，升序排列就是最小的排列。
 *         以 123465 为例：首先按照上一步，交换 5 和 4，得到 123564；然后需要将 5 之后的数重置为升序，得到 123546。
 *         显然 123546 比 123564 更小，123546 就是 123465 的下一个排列
 */

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() == 1) {
            return;
        }

        int min_swap_j = -1;
        int min_swap_i = -1;

        // 0, ..., j, ...., i, ..., end
        for (int i = nums.size() - 1; i >= 0; --i) {
            // 增加的幅度尽可能的小, 即交换的 j索引尽可能大, 当 i到达时就无法继续减少了
            if (i < min_swap_j) {
                break;
            }
            for (int j = i - 1; j >= 0; --j) {
                // b. 将一个 尽可能小的「大数」 与前面的「小数」交换。
                // i是大数的索引, j是小数的索引
                if (nums[i] > nums[j]) {
                    // 增加的幅度尽可能的小, 即交换的 j索引尽可能大
                    if (j > min_swap_j) {
                        min_swap_j = j;
                        min_swap_i = i;
                    }
                }
            }
        }

        // 如果有交换的话
        if (min_swap_i != -1) {
            swap(nums[min_swap_i], nums[min_swap_j]);
            sort(nums.begin() + min_swap_j + 1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};

int main() {
    vector<int> nums = {1, 2};

    Solution so;
    so.nextPermutation(nums);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}