/*************************
 * @file   : 41_.cpp
 * @encode : UTF-8
 * @note   : 添加与搜索单词 - 数据结构设计 https://leetcode.cn/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150
 * @date   : 2024/7/20 10
 *************************/

#include "iostream"
#include "vector"

using namespace std;

struct Node {
    bool is_end;
    vector<Node *> children;

    Node() {
        is_end = false;
        children = vector<Node *>(30, nullptr);
    }
};

int char2int(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return 29;
}

void insert(Node *root, string word) {
    Node *cur_node = root;

    for (char c: word) {
        int index = char2int(c);
        // 当前节点
        if (cur_node->children[index] == nullptr) {
            cur_node->children[index] = new Node();
        }
        cur_node = cur_node->children[index];
    }
    cur_node->is_end = true;
}

class WordDictionary {
public:
    Node *root = nullptr;


    WordDictionary() {
        root = new Node();
    }

    // addWord 中的 word 由小写英文字母组成
    void addWord(string word) {
        insert(root, word);
    }

    bool dfs(const string &word, int index, Node *node) {
        if (index == word.size()) {
            return node->is_end;
        }

        char cur_c = word[index];
        if (cur_c >= 'a' && cur_c <= 'z') {
            Node *child = node->children[char2int(cur_c)];
            if (child != nullptr) {
                if (dfs(word, index + 1, child)) {
                    return true;
                }
            }
        } else {
            // 遍历所有字符
            for (int i = 0; i < 26; ++i) {
                Node *child = node->children[i];
                if (child != nullptr) {
                    if (dfs(word, index + 1, child)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");

    cout << wd.search("pad") << endl;
    cout << wd.search("bad") << endl;
    cout << wd.search(".ad") << endl;
    cout << wd.search("b..") << endl;

    return 0;
}
