/*************************
 * @file   : 38_.cpp
 * @encode : UTF-8
 * @note   : 课程表 II https://leetcode.cn/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/19 15
 *************************/

#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "set"
#include "algorithm"

using namespace std;

class Solution {
public:
    unordered_map<int, set<int>> graph;

    // 其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> ret;
        int n = prerequisites.size();

        // 节点的出度
        vector<int> out_degree(numCourses + 2, 0);
        // 所有节点
        set<int> all_nodes;
        for (int i = 0; i < n; ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            // a --> b
            graph[b].insert(a);  // b被 哪些a指向了
            all_nodes.insert(a);
            all_nodes.insert(b);

            out_degree[a]++;
        }


        map<int, bool> visited;
        while (1) {
            bool break_flag = true;
            for (auto cur_node: all_nodes) {
                // 已经被访问过
                if (visited.find(cur_node) != visited.end()) {
                    continue;
                }

                if (out_degree[cur_node] <= 0) {
                    ret.push_back(cur_node);
                    visited[cur_node] = true;

                    // 修改出度
                    // 被哪些节点指向了
                    for (auto node: graph[cur_node]) {
                        out_degree[node]--;
                    }
                    break_flag = false;
                }
            }
            if (break_flag) {
                break;
            }

        }

        // 填充没有限制的课程
        if (ret.size() < numCourses) {
            for (int i = 0; i < numCourses; ++i) {
                if (all_nodes.find(i) != all_nodes.end()) {
                    continue;
                }
                ret.insert(ret.begin(), i);
            }
        }

        // 还是不满，说明有环
        if (ret.size() < numCourses) {
            return {};
        }

        return ret;
    }
};


int main() {
    int k = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

    Solution so;

    for (auto c: so.findOrder(k, prerequisites)) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}

