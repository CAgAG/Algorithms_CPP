/*************************
 * @file   : 22_.cpp
 * @encode : UTF-8
 * @note   : 存在重复元素 II https://leetcode.cn/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/13 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;


class Solution {
public:
    map<int, vector<int>> mq;  // 值和对应的索引

    bool containsNearbyDuplicate(vector<int> &nums, int k) {

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int cur_num = nums[i];

            if (mq.find(cur_num) == mq.end()) {  // 找不到
                mq[cur_num] = {i};
            } else {  // 可以找到

                for (auto index: mq[cur_num]) {
                    int dis = abs(index - i);
                    if (dis <= k) {
                        return true;
                    }
                }
                mq[cur_num].push_back(i);
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};

    Solution so;
    cout << so.containsNearbyDuplicate(nums, 1) << endl;

    return 0;
}