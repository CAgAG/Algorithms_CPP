/*************************
 * @file   : 21_.cpp
 * @encode : UTF-8
 * @note   : 单词规律 https://leetcode.cn/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/13 18
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "cstring"

using namespace std;


class Solution {
public:
    // 【双向连接的对应规律】，这说明pattern和每一个子串之间是双射关系，即pattern[i] 可以确定一个 string，一个string也可以确定一个pattern[i]
    map<char, string> mq;
    map<string, bool> visited;

    bool wordPattern(string pattern, string s) {

        int n = pattern.size();
        int cur_s_i = 0;
        for (int i = 0; i < n; ++i) {
            int cur_p = pattern[i];
            string cur_s = "";

            // 数量对不上
            if (cur_s_i >= s.size()) {
                return false;
            }

            while (s[cur_s_i] != ' ' && cur_s_i < s.size()) {
                cur_s += s[cur_s_i];
                cur_s_i++;
            }
            cur_s_i++;

            if (mq.find(cur_p) == mq.end()) { // 没找到
                mq[cur_p] = cur_s;
                if (visited.find(cur_s) != visited.end()) {
                    return false;
                }
                visited[cur_s] = true;
            } else {  // 可以找到
                if (mq[cur_p] != cur_s) {
                    return false;
                }
            }
        }

        // 数量对不上
        if (cur_s_i < s.size()) {
            return false;
        }


        return true;
    }
};

int main() {
    string pattern = "he";
    string s = "unit";

    Solution so;
    cout << so.wordPattern(pattern, s) << endl;

    return 0;
}