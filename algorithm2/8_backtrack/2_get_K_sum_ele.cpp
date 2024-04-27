/*************************
 * @file   : 2_get_K_sum_ele.cpp
 * @encode : UTF-8
 * @note   : 组合总和III https://leetcode.cn/problems/combination-sum-iii/description/
 * @date   : 2024/3/24 22
 *************************/

#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> ans;

public:
    void backtrack(int k, int n, int start_num, int cur_sum) {
        if (cur_sum > n) {  // 大于目标数 就没必要继续了
            return;
        }

        if (ans.size() == k) {
            if (cur_sum == n) {
                ret.push_back(ans);
            }
            return;
        }

        for (int i = start_num; i <= 9; ++i) {
            ans.push_back(i);
            cur_sum += i;
            backtrack(k, n, i + 1, cur_sum);
            ans.pop_back();
            cur_sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1, 0);
        return ret;
    }
};

int main() {
    int k = 3, n = 9;

    Solution so;
    auto result = so.combinationSum3(k, n);
    for (auto vecs: result) {
        for (auto vec: vecs) {
            cout << vec << " ";
        }
        cout << endl;
    }

    return 0;
}

