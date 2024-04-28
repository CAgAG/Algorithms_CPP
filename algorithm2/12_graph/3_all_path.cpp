/*************************
 * @file   : 3_all_path.cpp
 * @encode : UTF-8
 * @note   : 所有可能的路径 https://leetcode.cn/problems/all-paths-from-source-to-target/description/
 * @date   : 2024/4/27 21
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "set"

using namespace std;

// 请你找出所有从节点 0 到节点 n-1 的路径并输出

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(vector<vector<int>> &graph, int node) {
        if (node == graph.size() - 1) {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < graph[node].size(); ++i) {
            path.push_back(graph[node][i]);
            dfs(graph, graph[node][i]);
            path.pop_back();
        }
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        path.push_back(0);
        dfs(graph, 0);
        return ret;
    }
};

int main() {
    // graph[i] 是一个从节点 i 可以访问的所有节点的列表
    vector<vector<int>> graph = {
            {1, 2},
            {3},
            {3},
            {}
    };

    Solution so;

    for (auto its: so.allPathsSourceTarget(graph)) {
        for (int it: its) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}

