/*************************
 * @file   : 1_combine.cpp
 * @encode : UTF-8
 * @note   : 组合 https://leetcode.cn/problems/combinations/description/
 * @date   : 2024/3/17 15
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;

public:
    void backtrack(int n, int k, int start_num) {
        // 树的深度
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }

        // 树的宽度
        for (int i = start_num; i <= n; ++i) {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ret;
    }

    // =======================================================
    // 剪枝
    void backtrack2(int n, int k, int start_num) {
        // 树的深度
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }

        // 剩余可加入的数 必须等于大于 题目需要的 k个数
        if (n - start_num + 1 < k - path.size()) {
            return;
        }

        // 树的宽度
        for (int i = start_num; i <= n; ++i) {  // n - start_num + 1 >= k - path.size
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine2(int n, int k) {
        ret.clear();
        path.clear();

        backtrack2(n, k, 1);
        return ret;
    }
};

int main() {
    int n = 4, k = 3;

    Solution so;
    for (auto c1: so.combine(n, k)) {
        for (auto c2: c1) {
            cout << c2 << ", ";
        }
        cout << endl;
    }
    cout << "=======================" << endl;
    for (auto c1: so.combine2(n, k)) {
        for (auto c2: c1) {
            cout << c2 << ", ";
        }
        cout << endl;
    }
    return 0;
}