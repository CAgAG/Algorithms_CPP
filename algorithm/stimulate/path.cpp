/*************************
 * @file   : path.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/14 13
 *************************/

/* 一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走
 * 输入: 一个5×5的二维数组，表示一个迷宫。
 * 输出: 能否到达终点
 */

#include "queue"
#include "set"
#include "iostream"

using namespace std;

#define maze_len 5

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

int main() {
    int maze[maze_len][maze_len]{
            {0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 1, 0},
    };
    int target_index = maze_len - 1;

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});

    // 上下左右
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == target_index && y == target_index) {
            print_maze(maze, 5, 5);
            cout << "goal" << endl;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < maze_len && ny >= 0 && ny < maze_len && maze[nx][ny] == 0 \
                && visited.find({nx, ny}) == visited.end()) {
                visited.insert({nx, ny});
                q.push({nx, ny});
                maze[nx][ny] = 2;
            }
        }
    }

    return 0;
}