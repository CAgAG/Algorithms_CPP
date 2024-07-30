/*************************
 * @file   : merge_sort.cpp
 * @encode : UTF-8
 * @note   : https://leetcode.cn/problems/sort-an-array/description/
 * @date   : 2024/6/23 22
 *************************/

#include "iostream"
#include "vector"

using namespace std;


vector<int> tp_list;

void merge(vector<int> &list, int left_index, int mid_index, int right_index) {
    // 更新 对应部分的tp_list
    for (int i = left_index; i <= right_index; ++i) {
        tp_list[i] = list[i];
    }

    // [left_index, mid_index], [mid_index + 1, right_index]
    int l1_index = left_index;
    int l2_index = mid_index + 1;
    int cur_index = left_index;
    while (l1_index <= mid_index && l2_index <= right_index) {
        if (tp_list[l1_index] < tp_list[l2_index]) {
            list[cur_index] = tp_list[l1_index];
            l1_index++;
        } else {
            list[cur_index] = tp_list[l2_index];
            l2_index++;
        }
        cur_index++;
    }
    while (l1_index <= mid_index) {
        list[cur_index] = tp_list[l1_index];
        l1_index++;
        cur_index++;
    }
    while (l2_index <= right_index) {
        list[cur_index] = tp_list[l2_index];
        l2_index++;
        cur_index++;
    }
}

void merge_sort(vector<int> &list, int left_index, int right_index) {
    if (left_index < right_index) {
        int mid_index = (left_index + right_index) / 2;
        merge_sort(list, left_index, mid_index);
        merge_sort(list, mid_index + 1, right_index);
        merge(list, left_index, mid_index, right_index);
    }
}

// ==========================================
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            tp_list.push_back(nums[i]);
        }

        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 1};
    Solution so;

    for (int a: so.sortArray(nums)) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}