/*************************
 * @file   : dict_tree.cpp
 * @encode : UTF-8
 * @note   : 字典树可以用于查找字符串之间的相同前缀
 * @date   : 2024/2/15 16
 *************************/

#include <iostream>
#include <vector>

using namespace std;

// 定义字典树节点
struct TrieNode {
    vector<TrieNode *> children; // 存储子节点
    bool isEndOfWord; // 标记是否为单词的结尾

    // 初始化构造函数
    TrieNode() {
        isEndOfWord = false;
        children = vector<TrieNode *>(30, nullptr); // 假设只包含小写字母且多扩充4位备用
    }
};

// 插入单词到字典树
void insert(TrieNode *root, string word) {
    TrieNode *node = root;
    for (char c: word) {
        int index = c - 'a';  // 把字符转为数字坐标用于存储
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];  // 下一个节点
    }
    node->isEndOfWord = true;
}

// 查找单词在字典树中是否存在
bool search(TrieNode *root, string word) {
    TrieNode *node = root;
    for (char c: word) {
        int index = c - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWord;
}

// 深度遍历字典树
void dfs(TrieNode *node, string word) {
    if (node == nullptr) {
        return;
    }

    if (node->isEndOfWord) {
        cout << word << endl;
    }

    for (int i = 0; i < node->children.size(); ++i) {
        if (node->children[i] != nullptr) {
            word.push_back('a' + i);
            dfs(node->children[i], word);
            word.pop_back();
        }
    }
}


// 查找单词是否存在于前缀
bool search2(TrieNode *root, string word) {
    TrieNode *node = root;
    for (char c: word) {
        int index = c - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return true;
}

// 删除字典树中的单词（略）

int main() {
    TrieNode *root = new TrieNode();
    insert(root, "helloz");
    insert(root, "hellozhworld");
    insert(root, "hellxzhphone");

    cout << search2(root, "hello") << endl; // 输出1，表示存在
    cout << search2(root, "hell") << endl; // 输出0，表示不存在

    TrieNode* tp_root = root;
    dfs(tp_root, "");
    return 0;
}
