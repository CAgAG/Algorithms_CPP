/*************************
 * @file   : 53_.cpp
 * @encode : UTF-8
 * @note   : 单词搜索 II https://leetcode.cn/problems/word-search-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/27 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

struct Node {
    bool is_leaf;
    vector<Node *> children = vector<Node *>(27, nullptr);

    Node() {
        is_leaf = false;
    }

    Node(bool _is_leaf) {
        is_leaf = _is_leaf;
    }
};


class Solution {
public:
    Node *root = new Node();
    int m = 0;
    int n = 0;
    vector<vector<int>> direction = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };
    // 第一个字符的节点
    map<char, vector<Node*>> first_char_nodes;

    void
    build_tree(vector<vector<char>> board, int cur_x, int cur_y, map<pair<int, int>, bool> &visited, Node *cur_node) {

        for (int i = 0; i < direction.size(); ++i) {
            int may_x = cur_x + direction[i][0];
            int may_y = cur_y + direction[i][1];

            // 合法坐标
            if (may_x < 0 || may_y < 0 || may_x >= m || may_y >= n) {
                continue;
            }
            // 已经访问过
            if (visited.find({may_x, may_y}) != visited.end() && visited[{may_x, may_y}] == true) {
                continue;
            }
            // 添加位置
            first_char_nodes[board[may_x][may_y] - 'a'].push_back(cur_node);

            // 构建字典树
            if (cur_node->children[board[may_x][may_y] - 'a'] == nullptr) {
                cur_node->children[board[may_x][may_y] - 'a'] = new Node();
            }
            Node *tp_node = cur_node;
            // 回溯
            cur_node = cur_node->children[board[may_x][may_y] - 'a'];
            visited[{may_x, may_y}] = true;
            build_tree(board, may_x, may_y, visited, cur_node);
            visited[{may_x, may_y}] = false;
            cur_node = tp_node;
        }

    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        if (words.size() == 0) {
            return {};
        }

        m = board.size();
        n = board[0].size();
        map<pair<int, int>, bool> visited;
        visited[{0, 0}] = true;
        root->children[board[0][0] - 'a'] = new Node();
        first_char_nodes[board[0][0] - 'a'].push_back(root);

        build_tree(board, 0, 0, visited, root->children[board[0][0] - 'a']);

        vector<string> ret;
        for (int i = 0; i < words.size(); ++i) {
            char cur_c = words[i][0];
            // 找不到
            if (first_char_nodes.find(cur_c - 'a') == first_char_nodes.end()) {
                continue;
            }
            bool add_flag = false;
            for (Node *cur_node: first_char_nodes[cur_c - 'a']) {
                add_flag = true;
                for (int j = 0; j < words[i].size(); ++j) {
                    cur_c = words[i][j];
                    if (cur_node->children[cur_c - 'a'] == nullptr) {
                        add_flag = false;
                        break;
                    }
                    cur_node = cur_node->children[cur_c - 'a'];
                }
                if (add_flag) {
                    break;
                }
            }

            if (add_flag) {
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<char>> board = {
            {'a', 'b'}
    };
    vector<string> words = {"ba"};

    Solution so;
    for (auto s: so.findWords(board, words)) {
        cout << s << endl;
    }

    return 0;
}
