/*************************
 * @file   : 1_quick_sort.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/4/24 20
 *************************/

#include "iostream"
#include "vector"

using namespace std;

// 基准值左边小，右边大于
int get_pos(vector<int> &nums, int left, int right) {
    // 基准值
    int pivot = nums[left];
    while (left < right) {
        while (left < right && nums[right] > pivot) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void quick_sort(vector<int> &nums, int left, int right) {
    // 二叉树搜索
    if (left < right) {
        int pivot_index = get_pos(nums, left, right);
        quick_sort(nums, left, pivot_index - 1);
        quick_sort(nums, pivot_index + 1, right);
    }
}


int main() {
    vector<int> nums = {8, 9, 1, 2, 6, 5, 4};

    quick_sort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}