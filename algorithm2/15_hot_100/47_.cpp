/*************************
 * @file   : 47_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/27 17
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// Boyer-Moore 投票算法 (求众数-超半数)
/*
我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0
1. 我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：
1.1 如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
1.2 如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
end 在遍历完成后，candidate 即为整个数组的众数。
 */
class Solution {
public:
    int majorityElement(vector<int> &nums) {

        // 随便初始化, 保证count=0即可
        int ret = nums[0];
        int ret_count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == ret) {
                ret_count++;
            } else {
                ret_count--;
            }

            // 重新计数
            if (ret_count <= 0) {
                ret = nums[i];
                ret_count = 1;
            }
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};

    Solution so;
    cout << so.majorityElement(nums) << endl;

    return 0;
}