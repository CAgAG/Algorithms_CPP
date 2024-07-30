/*************************
 * @file   : 44_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/26 22
 *************************/

#include "iostream"
#include "stack"
#include "algorithm"

using namespace std;

// 保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cur_c = s[i];

            if (cur_c == ')') {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ret = max(ret, i - st.top());
                }
            } else {  // (
                st.push(i);
            }
        }

        return ret;
    }
};


int main() {

    string s = "()(()";

    Solution so;
    cout << so.longestValidParentheses(s) << endl;

    return 0;
}