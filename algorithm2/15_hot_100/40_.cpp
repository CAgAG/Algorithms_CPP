/*************************
 * @file   : 40_.cpp
 * @encode : UTF-8
 * @note   : kth 快排
 * @date   : 2024/6/25 20
 *************************/

#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

class Solution {
public:
    int target_index;

    // 返回排序后的基准值的位置
    int partitiom(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            // 找到 右边 第一个小于 基准值的索引: pivot, <==, right
            while (left < right && nums[right] > pivot) right--;
            nums[left] = nums[right];
            // 找到 左边 第一个大于 基准值的索引: left, ==>, pivot
            // 使用等于号, 移动基准值
            while (left < right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    int quick_sort(vector<int> &nums, int left, int right, int k) {
        if (left == right) {
            return left;
        }

        if (left < right) {
            int p_index = partitiom(nums, left, right);

            if (p_index == target_index) {
                return p_index;
            }

            if (p_index > target_index) {  // 在目标位置的右边
                return quick_sort(nums, left, p_index - 1, k);  // 向左边搜索
            }
            if (p_index < target_index) {  // 在目标位置的左边
                return quick_sort(nums, p_index + 1, right, k);  // 向右边搜索
            }
        }

        return -1;  // 不重要
    }

    int findKthLargest(vector<int> &nums, int k) {
        if (nums.size() == 1) {
            return nums[0];
        }

        target_index = nums.size() - k;
        return nums[quick_sort(nums, 0, nums.size() - 1, k)];
    }
};

int main() {
    vector<int> nums = {-1, 2, 0};
    int k = 2;

    Solution so;
    cout << so.findKthLargest(nums, k) << endl;

    return 0;
}