/*************************
 * @file   : dfs_num.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/23 17
 *************************/

/* 输入n，按字典序输出所有1~n的全排列，n不超过10 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 3;
vector<int> path;
int vis[11];

void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


void dfs(int cur_length) {
    if (cur_length == N + 1) {
        print_vector(path);
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (vis[i] != 1) {
            vis[i] = 1;
            path.push_back(i);
            dfs(cur_length + 1);
            vis[i] = 0;
            path.pop_back();
        }
    }
}

int main() {
    dfs(1);

    cout << "====================" << endl;
    // 使用标准库实现
    vector<int> nums;
    for (int i = 1; i <= N; ++i) {
        nums.push_back(i);
    }
    do {
        print_vector(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}