/*************************
 * @file   : 40_.cpp
 * @encode : UTF-8
 * @note   : 最小基因变化 https://leetcode.cn/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/20 09
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "set"
#include "unordered_set"
#include "queue"

using namespace std;


class Solution {
public:
    // 一次基因变化就意味着这个基因序列中的一个字符发生了变化
    bool can_trans(string s, string k) {
        int n = s.size();
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != k[i]) {
                diff++;
                if (diff >= 2) {
                    return false;
                }
            }
        }
        return true;
    }

    map<string, unordered_set<string>> graph;

    int minMutation(string startGene, string endGene, vector<string> &bank) {
        int n = bank.size();
        if (n == 0) {
            return -1;
        }

        // 建图
        // 第一个
        for (int i = 0; i < n; ++i) {
            if (can_trans(startGene, bank[i])) {
                graph[startGene].insert(bank[i]);
            }
        }
        // bank
        bool end_in_bank = false;
        for (int i = 0; i < n; ++i) {
            if (bank[i] == endGene) {
                end_in_bank = true;
            }

            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (can_trans(bank[i], bank[j])) {
                    graph[bank[i]].insert(bank[j]);
                }

            }
        }

        if (!end_in_bank) {
            return -1;
        }

        // 广度搜索
        queue<pair<string, int>> que;
        que.push({startGene, 0});
        map<string, bool> visited;

        while (!que.empty()) {
            auto cur_ele = que.front();
            que.pop();

            string cur_str = cur_ele.first;
            int cur_count = cur_ele.second;
            visited[cur_str] = true;

            for (string next_str: graph[cur_str]) {
                if (next_str == endGene) {
                    return cur_count + 1;
                }
                // 未访问过
                if (visited.find(next_str) == visited.end()) {
                    visited[next_str] = true;
                    que.push({next_str, cur_count + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    // string 长度都是 8
    string s = "AACCGGTT";
    string e = "AAACGGTA";

    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    Solution so;
    cout << so.minMutation(s, e, bank) << endl;

    return 0;
}