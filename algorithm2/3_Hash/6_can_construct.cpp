/*************************
 * @file   : 6_can_construct.cpp
 * @encode : UTF-8
 * @note   : 赎金信 https://leetcode.cn/problems/ransom-note/
 * @date   : 2024/3/2 12
 *************************/

#include "iostream"
#include "unordered_map"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;  // 统计 字符出现的次数
        for (char ch: magazine) {
            map[ch]++;
        }
        for (char ch: ransomNote) {
            bool can_find = map.find(ch) != map.end() && map[ch] != 0;
            if (can_find) {
                map[ch]--;
            } else {
                return false;
            }
        }
        return true;
    }

    // O(n)
    bool canConstruct2(string ransomNote, string magazine) {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j] - 'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string rn = "aa";
    string m = "aba";

    Solution so;
    cout << so.canConstruct(rn, m) << endl;
    cout << so.canConstruct2(rn, m) << endl;
    return 0;
}