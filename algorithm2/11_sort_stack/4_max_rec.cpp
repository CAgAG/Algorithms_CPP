/*************************
 * @file   : 4_max_rec.cpp
 * @encode : UTF-8
 * @note   : 柱状图中最大的矩形 https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 * @date   : 2024/4/27 18
 *************************/

#include "vector"
#include "iostream"
#include "stack"

using namespace std;

class Solution {
public:
    // 对于每个 i 找左右第一个比它小的数，拼接成德面积就是要求的面积之一
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 1) return heights[0];
        // 首尾拼接 0，
        // 尾0: 防止出现 [2, 4, 6, 8] 可以全部入栈的情况
        // 首0: 防止出现 [8, 6, 4, 2] 导致全部空栈的情况
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);

        int ret = 0;

        stack<int> st;
        st.push(0);
        for (int i = 1; i < heights.size(); ++i) {
            int cur_h = heights[i];
            int top_h = heights[st.top()];

            if (cur_h >= top_h) {
                st.push(i);
            } else {
                int right_index = i;
                int mid_index = -1, left_index = -1;
                while (!st.empty() && cur_h < heights[st.top()]) {
                    mid_index = st.top();
                    st.pop();
                    if (!st.empty()) {
                        left_index = st.top();

                        int rec_h = heights[mid_index];
                        int rec_w = right_index - left_index - 1;
                        int area = rec_h * rec_w;
                        ret = max(ret, area);
                    }
                }
                st.push(i);
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {2, 1, 5, 6, 2, 3};

    Solution so;
    cout << so.largestRectangleArea(nums) << endl;
    return 0;
}