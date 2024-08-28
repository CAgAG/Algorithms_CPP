/*************************
 * @file   : 45_conbime2.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/19 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:

    vector<int> path;
    vector<vector<int>> ret;

    void backtrace(int k, int n, int cur_sum, int start_num) {
        if (cur_sum == n && path.size() == k) {
            ret.push_back(path);
            return;
        }
        if (cur_sum > n || path.size() > k) {
            return;
        }

        for (int i = start_num; i <= 9; ++i) {
            path.push_back(i);
            backtrace(k, n, cur_sum + i, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrace(k, n, 0, 1);
        return ret;
    }
};

int main() {
    int k = 3;
    int n = 7;

    Solution so;
    for (auto as: so.combinationSum3(k, n)) {
        for (auto a: as) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}