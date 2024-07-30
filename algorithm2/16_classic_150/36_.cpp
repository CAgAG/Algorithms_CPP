/*************************
 * @file   : 36_.cpp
 * @encode : UTF-8
 * @note   : 克隆图 https://leetcode.cn/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/18 10
 *************************/

#include "iostream"
#include "vector"
#include "map"
#include "queue"
#include "algorithm"

using namespace std;


class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    Node *cloneGraph(Node *node) {
        if (!node)return nullptr;    // 空节点不拷贝
        // 节点是否已经被访问
        unordered_map<int, Node *> cloneNodes = {{node->val, new Node(node->val)}};  // 存储每一个拷贝过的节点

        queue<Node *> queue_;     // 用于广度优先搜索的队列
        queue_.push(node);  // 起点节点入队
        Node *cur;   // 获取当前处理的节点
        while (!queue_.empty()) {
            cur = queue_.front();     // 从队列中获取一个待处理的节点
            queue_.pop();
            Node *cloneNode = cloneNodes[cur->val];   // 待处理的节点一定是克隆好了的，直接获取其克隆节点

            for (auto &neighbor: cur->neighbors) {
                // 处理当前节点的邻接节点
                if (cloneNodes.find(neighbor->val) == cloneNodes.end()) {  // 【没找到，先克隆】
                    cloneNodes[neighbor->val] = new Node(neighbor->val);  // 如果邻接节点未拷贝，则拷贝
                    queue_.push(neighbor);      // 未拷贝的节点说明还没有处理，加入队列等待处理
                }
                cloneNode->neighbors.push_back(cloneNodes[neighbor->val]);  // 将邻接节点的拷贝节点加入当前节点的拷贝节点的邻接列表
            }
        }
        return cloneNodes[node->val];    // 返回起点节点的克隆节点
    }

};
