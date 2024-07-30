/*************************
 * @file   : 30_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/24 12
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
#include "queue"

using namespace std;

class Solution {
public:
    void topo_sort(map<int, vector<int>> &mp, map<int, int> &indegree_mp) {
        queue<int> que;

        for (auto d = indegree_mp.begin(); d != indegree_mp.end(); ++d) {
            if (d->second == 0) {
                que.push(d->first);
            }
        }

        while (!que.empty()) {
            int node = que.front();
            que.pop();

            if (mp.find(node) != mp.end()) {
                for (int i = 0; i < mp[node].size(); ++i) {
                    indegree_mp[mp[node][i]]--;

                    if (indegree_mp[mp[node][i]] == 0) {
                        que.push(mp[node][i]);
                    }
                }
            }
        }

    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // 构建图
        int n = prerequisites.size();
        if (n == 0) {
            return true;
        }

        map<int, vector<int>> mp;
        map<int, int> indegree_mp;
        for (int i = 0; i < numCourses; ++i) {
            indegree_mp[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int f = prerequisites[i][0];
            int s = prerequisites[i][1];
            if (f == s) {
                return false;
            }
            indegree_mp[f]++;
            mp[s].push_back(f);
        }
        topo_sort(mp, indegree_mp);
        for (auto d = indegree_mp.begin(); d != indegree_mp.end(); ++d) {
            if (d->second > 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int k = 5;
    vector<vector<int>> nums = {
            {1, 4},
            {2, 4},
            {3, 1},
            {3, 2},
    };

    Solution so;
    cout << so.canFinish(k, nums) << endl;

    return 0;
}