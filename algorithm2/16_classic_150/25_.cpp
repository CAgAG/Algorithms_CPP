/*************************
 * @file   : 25_.cpp
 * @encode : UTF-8
 * @note   : 简化路径 https://leetcode.cn/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/14 20
 *************************/

#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

class Solution {
public:
    stack<string> st;

    string simplifyPath(string path) {

        int n = path.size();

        for (int i = 0; i < n; ++i) {
            char cur_c = path[i];

            if (cur_c == '/') {
                i++;
                string ele = "";
                while (i < n && path[i] != '/') {
                    ele.push_back(path[i]);
                    i++;
                }
                i--;
                if (ele == "." || ele == "") {
                    continue;
                }
                if (ele == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                    continue;
                }
                st.push(ele);
            }

        }

        string ret = "";
        while (!st.empty()) {
            ret = "/" + st.top() + ret;
            st.pop();
        }
        if (ret == "") {
            return "/";
        }
        return ret;
    }
};

int main() {
    string s = "/a/./b/../../c/";

    Solution so;
    cout << so.simplifyPath(s) << endl;

    return 0;
}