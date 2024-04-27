/*************************
 * @file   : 2_next_greater_num.cpp
 * @encode : UTF-8
 * @note   : 下一个更大元素 I https://leetcode.cn/problems/next-greater-element-i/description/
 * @date   : 2024/4/26 23
 *************************/

#include "iostream"
#include "vector"
#include "stack"
#include "map"

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ret(nums1.size(), -1);

        map<int, int> n1_i;  // nums 1中 值 对 索引的映射
        for (int i = 0; i < nums1.size(); ++i) {
            n1_i[nums1[i]] = i;
        }

        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums2.size(); ++i) {
            int cur_n2 = nums2[i];

            if (cur_n2 <= nums2[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && cur_n2 > nums2[st.top()]) {
                    // 只对 nums1 里的元素求单调栈
                    bool in_nums1 = n1_i.find(nums2[st.top()]) != n1_i.end(); // 在 nums1 中
                    if (in_nums1) {
                        ret[n1_i[nums2[st.top()]]] = cur_n2;
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    Solution so;
    for (int t: so.nextGreaterElement(nums, nums2)) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}