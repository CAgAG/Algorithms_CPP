/*************************
 * @file   : 14_split_letter_range.cpp
 * @encode : UTF-8
 * @note   : 划分字母区间 https://programmercarl.com/0763.%E5%88%92%E5%88%86%E5%AD%97%E6%AF%8D%E5%8C%BA%E9%97%B4.html
 * @date   : 2024/4/21 19
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

// 把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中
/*
在遍历的过程中相当于是要找每一个字母的边界，如果找到之前遍历过的所有字母的最远边界，说明这个边界就是分割点了。
 此时前面出现过所有字母，最远也就到这个边界了。
可以分为如下两步：
    统计每一个字符最后出现的位置
    从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last_letter_index[27] = {0};
        // 统计每一个字符最后出现的位置
        for (int i = 0; i < s.size(); ++i) {
            last_letter_index[s[i] - 'a'] = i;
        }

        vector<int> ret;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i) {
            // 找到字符出现的最远边界
            right = max(right, last_letter_index[s[i] - 'a']);  // 同一字母最多出现在一个片段中, 所以才要找最远的
            if (i == right) {  // 达到 当前字符串中的字符所能到达的最远距离
                // left 只是使用于计算字符个数
                ret.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return ret;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";

    Solution so;

    for (int it: so.partitionLabels(s)) {
        cout << it << endl;
    }

    return 0;
}