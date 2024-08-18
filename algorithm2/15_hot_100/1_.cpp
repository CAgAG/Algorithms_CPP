/*************************
 * @file   : 1_.cpp
 * @encode : UTF-8
 * @note   : 字母异位词分组 https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked
 * @date   : 2024/6/21 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    vector<vector<string>> ret;

    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); ++i) {
            string cur_s = strs[i];
            // 排序，统一 key
            sort(cur_s.begin(), cur_s.end());
            if (mp.find(cur_s) != mp.end()) {
                mp[cur_s].push_back(i);
            } else {
                mp[cur_s] = {i};
            }
        }


        for (auto i = mp.begin(); i != mp.end(); ++i) {

            vector<string> path;
            for (int j = 0; j < i->second.size(); ++j) {
                path.push_back(strs[i->second[j]]);
            }
            ret.push_back(path);
        }

        return ret;
    }
};

int main() {
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution so;
    for (auto ss: so.groupAnagrams(s)) {
        for (auto as: ss) {
            cout << as << " ";
        }
        cout << endl;
    }

    return 0;
}