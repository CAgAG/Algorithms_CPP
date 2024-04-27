/*************************
 * @file   : 1_split_cookie.cpp
 * @encode : UTF-8
 * @note   : 分发饼干 https://leetcode.cn/problems/assign-cookies/description/
 * @date   : 2024/3/27 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0;

        for (int i = 0; i < s.size(); ++i) {
            int cur_cookie = s[i];
            for (int j = 0; j < g.size(); ++j) {
                int cur_eat = g[j];
                // 只要找到可以满足胃口的小孩就给饼干
                if (cur_cookie >= cur_eat && cur_eat != -1) {
                    ret++;
                    g[j] = -1;  // 标记为已给过饼干
                    break;
                }
            }
        }
        return ret;
    }

    int findContentChildren2(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index = 0;  // 胃口索引
        for(int i = 0; i < s.size(); i++) { // 饼干
            // 胃口只要能被饼干填饱, 就直接给
            if(index < g.size() && g[index] <= s[i]){ // 胃口
                index++;
            }
        }
        return index;
    }
};

int main() {
    // 胃口值: g, 饼干: s; s >= g
    // 每个孩子最多只能给一块饼干
    vector<int> g = {1, 2, 3}, s = {1, 1};

    Solution so;
    cout << so.findContentChildren(g, s) << endl;
    cout << so.findContentChildren2(g, s) << endl;

    return 0;
}