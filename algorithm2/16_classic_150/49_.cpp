/*************************
 * @file   : 49_.cpp
 * @encode : UTF-8
 * @note   : O(1) 时间插入、删除和获取随机元素 https://leetcode.cn/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/23 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

// 哈希表可以在 O(1) 的时间内完成插入和删除操作

class RandomizedSet {
public:
    // 值：索引
    map<int, int> exist;
    vector<int> nums;

    RandomizedSet() {

    }

    bool insert(int val) {
        // 不存在
        if (exist.find(val) == exist.end()) {
            nums.push_back(val);
            exist[val] = nums.size() - 1;
            return true;
        }
        // 存在
        return false;
    }

    bool remove(int val) {
        // 存在
        if (exist.find(val) != exist.end()) {
            int index = exist[val];
            // 将变长数组的最后一个元素 last 移动到下标 index 处，在哈希表中将 last 的下标更新为 index；
            int last_num = nums[nums.size() - 1];
            nums[index] = last_num;
            exist[last_num] = index;

            // 删除
            nums.pop_back();
            exist.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        // rand(): 可以产生一个0~32767之间的随机数
        int index = rand() % nums.size();
        return nums[index];
    }
};

int main() {

    return 0;
}