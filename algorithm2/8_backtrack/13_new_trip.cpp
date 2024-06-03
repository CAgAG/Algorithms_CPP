/*************************
 * @file   : 13_new_trip.cpp
 * @encode : UTF-8
 * @note   : 重新安排行程 https://leetcode.cn/problems/reconstruct-itinerary/description/
 * @date   : 2024/3/26 12
 *************************/

#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "unordered_map"

using namespace std;

class Solution {
private:
    // unordered_map<出发机场, map<到达机场, 剩余可用航班次数>> targets
    // 注意 map 是有序的, unordered_map 才是无序的
    unordered_map<string, map<string, int>> targets;

public:
    // 注意函数返回值我用的是bool
    // 因为我们只需要找到一个路径，就是在树形结构中唯一的一条通向叶子节点的路线
    bool backtrace(int ticketNum, vector<string> &ret) {
        // 到达叶子节点
        if (ret.size() == ticketNum + 1) {
            // for (string r: ret) {
            //     cout << r << " ";
            // }
            // cout << endl;
            return true;
        }

        string last_from_p = ret[ret.size() - 1];
        for (pair<const string, int> &target: targets[last_from_p]) {
            // 记录到达机场是否飞过了
            if (target.second > 0) {  // 没飞过（还可以飞）
                string to_p = target.first;

                ret.push_back(to_p);
                target.second--; // 已飞过一次

                // backtrace(ticketNum, ret);
                if (backtrace(ticketNum, ret)) {
                    return true;
                }
                ret.pop_back();
                target.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (const vector<string> &vec: tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        vector<string> ret;
        ret.push_back("JFK"); // 起始机场
        backtrace(tickets.size(), ret);
        return ret;
    }
};

int main() {

    vector<vector<string>> tickets = {{"JFK", "SFO"},
                                      {"JFK", "ATL"},
                                      {"SFO", "ATL"},
                                      {"ATL", "JFK"},
                                      {"ATL", "SFO"}};

    Solution so;
    auto result = so.findItinerary(tickets);
    for (auto vecs: result) {
        cout << vecs << " ";
    }
    cout << endl;
    return 0;
}

// class Solution {
// private:
//     vector<string> path;
//     vector<string> ret;
//     vector<bool> used;
//
// public:
//     bool is_all_used() {
//         for (int i = 0; i < used.size(); ++i) {
//             if (used[i] == false) {
//                 return false;
//             }
//         }
//         return true;
//     }
//
//     void backtrace(vector<vector<string>> &tickets) {
//         if (is_all_used()) {
//             ret = vector<string>(path.begin(), path.end());
//             return;
//         }
//
//         for (int i = 0; i < tickets.size(); ++i) {
//             if (used[i] == true) {
//                 continue;
//             }
//
//             vector<string> ft = tickets[i];
//             string from_p = ft[0];
//             string to_p = ft[1];
//             string cur_p = path[path.size() - 1];
//
//             if (cur_p == from_p) {
//                 path.push_back(to_p);
//                 used[i] = true;
//                 backtrace(tickets);
//                 path.pop_back();
//                 used[i] = false;
//             }
//         }
//     }
//
//     vector<string> findItinerary(vector<vector<string>> &tickets) {
//         path.push_back("JFK");
//         used = vector<bool>(tickets.size(), false);
//         backtrace(tickets);
//         return ret;
//     }
// };