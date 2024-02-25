/*************************
 * @file   : dfs_num.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/23 17
 *************************/

/* 给定一个n个元素的集合，枚举集合 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 3;
vector<int> path;
vector<int> nums_set;
int vis[N + 1];

void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


void dfs(int cur_length) {
    if (cur_length == N) {
        print_vector(path);
        return;
    }

    // 不选择元素
    dfs(cur_length + 1);
    // 选择元素
    path.push_back(nums_set[cur_length]);
    dfs(cur_length + 1);
    path.pop_back();
}

int main() {
    for (int i = 0; i < N; ++i) {
        nums_set.push_back(i);
    }

    dfs(0);

    return 0;
}