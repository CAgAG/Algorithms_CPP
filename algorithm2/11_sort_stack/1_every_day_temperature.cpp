/*************************
 * @file   : 1_every_day_temperature.cpp
 * @encode : UTF-8
 * @note   : 每日温度 https://leetcode.cn/problems/daily-temperatures/description/
 * @date   : 2024/4/26 23
 *************************/

#include "iostream"
#include "vector"
#include "stack"

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> st; // 存放的是对应数值的索引
        vector<int> ret(temperatures.size(), 0);

        st.push(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            int cur_t = temperatures[i];
            int top_t = temperatures[st.top()];

            if (cur_t <= top_t) {
                // 符合单调性, 加入
                st.push(i);
            } else {  // 不符合单调性
                while (!st.empty() && cur_t > temperatures[st.top()]) {  // 循环弹出指导找到符合 当前元素 单调性的位置
                    ret[st.top()] = i - st.top();  // 索引做运算
                    st.pop(); // 破坏单调性，弹出
                }
                // 加入当前元素
                st.push(i);
            }
        }
        // 不需要管单调栈里的元素，因为初始化本来就是 0
        return ret;
    }
};

int main() {
    vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution so;
    for (int t: so.dailyTemperatures(nums)) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}