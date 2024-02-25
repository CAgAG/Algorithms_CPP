/*************************
 * @file   : path.cpp
 * @encode : UTF-8
 * @note   : 深度遍历 + 栈(显示路径)
 * @date   : 2024/2/14 13
 *************************/

/* 一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
 * 输入: 一个5×5的二维数组，表示一个迷宫。数据保证有唯一解。
 * 输出: 左上角到右下角的最短路径
 */

#include "stack"
#include "queue"
#include "vector"
#include "set"
#include "iostream"

using namespace std;

#define maze_len 5

int target_index_i = maze_len - 1;
int target_index_j = maze_len - 1;
int maze[maze_len][maze_len] = {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
};
stack<pair<int, int>> path;
set<pair<int, int>> visited;
int direction_i[] = {0, 1, 0, -1};
int direction_j[] = {1, 0, -1, 0};

void print_maze(int (*maze)[maze_len], int len_row, int len_col) {
    for (int i = 0; i < len_col; ++i) {
        for (int j = 0; j < len_row; ++j) {
            if (maze[i][j] < 0) {
                cout << maze[i][j] << " ";
            } else {
                cout << " " << maze[i][j] << " ";
            }

        }
        cout << endl;
    }
}

void print_stack(stack<pair<int, int>> q, bool reverse = false) {
    stack<pair<int, int>> temp = q; // 创建一个临时队列，用于遍历
    if (!reverse) {
        while (!temp.empty()) {
            cout << "(" << temp.top().first << ", " << temp.top().second << ") ";
            temp.pop();
        }
        cout << endl;
    } else {
        stack<pair<int, int>> temp2;
        while (!temp.empty()) {
            temp2.push(temp.top());
            temp.pop();
        }

        while (!temp2.empty()) {
            cout << "(" << temp2.top().first << ", " << temp2.top().second << ") ";
            temp2.pop();
        }
        cout << endl;
    }
}

void dfs(int m_i, int m_j) {
    if (m_i == target_index_i && m_j == target_index_j) {
        cout << "========= final path ===========" << endl;
        print_stack(path, true);
        cout << "========= final path ===========" << endl;
        return;
    }

    for (int d = 0; d < 4; ++d) {
        int next_i = m_i + direction_i[d];
        int next_j = m_j + direction_j[d];

        if (next_i < maze_len && next_j < maze_len && next_i >= 0 && next_j >= 0 &&
            maze[next_i][next_j] != 1 &&
            visited.find({next_i, next_j}) == visited.end()) {
            path.push({next_i, next_j});
            visited.insert({next_i, next_j});
            // =============== display path ===============
            maze[next_i][next_j] = 2;
            print_stack(path);

            dfs(next_i, next_j);
            path.pop();
        }
    }
}

int main() {
    path.push({0, 0});
    visited.insert({0, 0});
    dfs(0, 0);

    cout << "================================" << endl;
    print_maze(maze, maze_len, maze_len);
    return 0;
}