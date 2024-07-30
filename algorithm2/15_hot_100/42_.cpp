/*************************
 * @file   : 42_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/26 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows + 1);
        ret[1] = {1};
        if (numRows == 1) {
            ret.erase(ret.begin());
            return ret;
        }
        int cur_row = 2;
        for (; cur_row <= numRows; ++cur_row) {
            for (int i = 0; i < cur_row; ++i) {
                int pre_len = ret[cur_row - 1].size();
                int left, right;
                if (i >= pre_len) {
                    right = 0;
                } else {
                    right = ret[cur_row - 1][i];
                }
                if (i - 1 < 0) {
                    left = 0;
                } else {
                    left = ret[cur_row - 1][i - 1];
                }
                ret[cur_row].push_back(left + right);
            }
        }
        ret.erase(ret.begin());
        return ret;
    }
};

int main() {
    int k = 5;

    Solution so;
    for (auto as: so.generate(k)) {
        for (auto a: as) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}