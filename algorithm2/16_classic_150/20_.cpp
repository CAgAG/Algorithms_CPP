/*************************
 * @file   : 20_.cpp
 * @encode : UTF-8
 * @note   : 同构字符串 https://leetcode.cn/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/13 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "cstring"

using namespace std;

/*
不同字符【不能】映射到同一个字符上，
 相同字符只能映射到同一个字符上
 */

class Solution {
public:
    map<char, char> mp;
    vector<bool> visited = vector<bool>(256);  // 键值是否已被访问

    bool isIsomorphic(string s, string t) {

        int n = s.size();

        for (int i = 0; i < n; ++i) {
            char cur_s = s[i];
            char cur_t = t[i];

            if (mp.find(cur_s) == mp.end()) {  // 找不到
                mp[cur_s] = cur_t;
                if (visited[cur_t]) {  // 不同字符【不能】映射到同一个字符上
                    return false;
                }
                visited[cur_t] = true;
            } else {  // 可以找到
                if (mp[cur_s] != cur_t) {  // 不符合有映射
                    return false;
                }
            }

        }

        return true;
    }
};

int main() {
    string s = "egg";
    string t = "add";

    Solution so;
    cout << so.isIsomorphic(s, t) << endl;

    return 0;
}