/*************************
 * @file   : 3_catch_rain.cpp
 * @encode : UTF-8
 * @note   : 接雨水 https://leetcode.cn/problems/trapping-rain-water/description/
 * @date   : 2024/4/27 15
 *************************/

#include "iostream"
#include "vector"
#include "stack"
#include "map"

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) return 0; // 可以不加

        int ret = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); ++i) {
            int cur_h = height[i];
            int top_h = height[st.top()];

            if (cur_h <= top_h) {
                st.push(i);
            } else {
                int right_index = i;
                int mid_index = -1, left_index = -1;
                while (!st.empty() && cur_h > height[st.top()]) {
                    mid_index = st.top();
                    st.pop();
                    if (!st.empty()) {
                        left_index = st.top();
                        // 横向(从左向右看) 计算雨水的高和宽
                        int rain_h = min(height[left_index], height[right_index]) - height[mid_index];
                        int rain_w = right_index - left_index - 1;  // 右边 - 左边，因为在循环中 右边是不变的
                        int area = rain_h * rain_w;
                        ret += area;
                    }
                }
                st.push(i);
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution so;
    cout << so.trap(nums) << endl;
    return 0;
}