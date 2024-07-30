/*************************
 * @file   : Fisher_Yates.cpp
 * @encode : UTF-8
 * @note   : Fisher-Yates (Knuth) 洗牌算法
 * @date   : 2024/6/26 16
 *************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib> // 包含rand()和 srand()

using namespace std;

// 时间复杂度为 O(n), 空间复杂度为 O(1)
void Knuth_Shuffle(vector<int> &nums) {
    srand(time(nullptr)); // 使用当前时间作为随机数种子
    // 0, ..., j(i), ..., end
    for (int end = nums.size() - 1; end > 0; --end) {
        int j = rand() % (end + 1); // 生成 0 到 i 的随机索引
        swap(nums[end], nums[j]);
    }
}

// 时间复杂度为 O(n log(n)), 空间复杂度为 O(n)
void Quick_Shuffle(vector<int> &nums, int start, int end) {
    if (start >= end) {
        return;
    }

    srand(time(nullptr)); // 使用当前时间作为随机数种子
    int j = start + rand() % (end - start);
    swap(nums[start], nums[j]);

    Quick_Shuffle(nums, start + 1, end);
    Quick_Shuffle(nums, start, end - 1);
}

int main() {
    cout << "Knuth_Shuffle" << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Knuth_Shuffle(nums);
    for (int num: nums) {
        std::cout << num << " ";
    }
    cout << endl;

    cout << "Quick_Shuffle" << endl;
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Quick_Shuffle(nums, 0, nums.size() - 1);
    for (int num: nums) {
        std::cout << num << " ";
    }
    cout << endl;
    return 0;
}