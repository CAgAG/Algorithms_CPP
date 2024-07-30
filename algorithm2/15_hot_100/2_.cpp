/*************************
 * @file   : 2_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/21 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int ret = 1;
        set<int> nums_set(nums.begin(), nums.end());

        for (int num: nums_set) {

            int pre_num = num - 1;
            if (nums_set.find(pre_num) == nums_set.end()) {  // 前面没有数，表明该数可能是连续序列的开头
                int cur_length = 0;
                pre_num = num;
                while (nums_set.find(pre_num) != nums_set.end()) {
                    cur_length++;
                    pre_num++;
                }
                ret = max(ret, cur_length);
            }
        }


        return ret;
    }
};

int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution so;
    cout << so.longestConsecutive(nums) << endl;

    return 0;
}