/*************************
 * @file   : 2_next_greater_num.cpp
 * @encode : UTF-8
 * @note   : 下一个更大元素 II https://leetcode.cn/problems/next-greater-element-ii/description/
 * @date   : 2024/4/26 23
 *************************/

#include "iostream"
#include "vector"
#include "stack"
#include "map"

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> ret(nums.size(), -1);

        map<int, int> i2num;
        for (int i = 0; i < nums.size(); ++i) {
            i2num[nums[i]] = i;
        }

        stack<int> st;
        st.push(0);
        for (int j = 1; j < nums.size() * 2; ++j) {
            int i = j % nums.size();  // 相当于拼接一个一样的数组

            int cur_num = nums[i];
            int top_num = nums[st.top()];

            if (cur_num <= top_num) {
                st.push(i);
            } else {
                while (!st.empty() && cur_num > nums[st.top()]) {
                    ret[st.top()] = cur_num;
                    st.pop();
                }
                st.push(i);
            }
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};

    Solution so;
    for (int t: so.nextGreaterElements(nums)) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}