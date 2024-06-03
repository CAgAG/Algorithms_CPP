/*************************
 * @file   : 11_rebuild_queue.cpp
 * @encode : UTF-8
 * @note   : 根据身高重建队列 https://leetcode.cn/problems/queue-reconstruction-by-height/description/
 * @date   : 2024/4/15 14
 *************************/
// people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;


void print_vec(vector<vector<int>> nums) {
    for (vector<int> it: nums) {
        for (int v: it) {
            cout << v << ", ";
        }
        cout << endl;
    }
}

class Solution {
private:
    static bool cmp(const vector<int> &a, vector<int> &b) {
        // 身高相同, 次数少的在前
        if (a[0] == b[0]) return a[1] < b[1];
        // 身高高的在前
        return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmp);

        // print_vec(people);
        // cout << "====================" << endl;

        // 强制插入到指定位次
        vector<vector<int>> ret;
        for (int i = 0; i < people.size(); ++i) {
            int pos = people[i][1];
            ret.insert(ret.begin() + pos, people[i]);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> people = {
            {7, 0},
            {4, 4},
            {7, 1},
            {5, 0},
            {6, 1},
            {5, 2}
    };

    Solution so;
    print_vec(so.reconstructQueue(people));
    return 0;
}


