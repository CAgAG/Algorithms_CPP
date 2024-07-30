/*************************
 * @file   : 30_.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/24 12
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
#include "queue"

using namespace std;

struct Node {
    vector<Node *> children;
    bool is_end;

    Node() {
        is_end = false;
        children = vector<Node *>(26, nullptr);
    }
};

class Trie {
public:
    Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *cur_node = root;
        for (char c: word) {
            int index = c - 'a';
            if (cur_node->children[index] == nullptr) {
                cur_node->children[index] = new Node();
            }
            cur_node = cur_node->children[index];
        }
        cur_node->is_end = true;
    }

    bool search(string word) {
        Node *cur_node = root;
        for (char c: word) {
            int index = c - 'a';
            if (cur_node->children[index] == nullptr) {
                return false;
            }
            cur_node = cur_node->children[index];
        }
        return cur_node->is_end;
    }

    bool startsWith(string prefix) {
        Node *cur_node = root;
        for (char c: prefix) {
            int index = c - 'a';
            if (cur_node->children[index] == nullptr) {
                return false;
            }
            cur_node = cur_node->children[index];
        }
        return true;
    }
};

// ===================================
// 辅助函数，用于检查子节点是否为叶子节点（即没有其他子节点和单词结束标记）
bool isLeaf(Node *node) {
    return node->children.empty() && !node->is_end;
}

// 递归地删除字典树中的单词
void deleteWord(Node *&node, string word, int index = 0) {
    if (node == nullptr || index == word.size()) {
        return;
    }

    int charIndex = word[index] - 'a';
    // 递归到下一个字符
    deleteWord(node->children[charIndex], word, index + 1);

    // 如果当前节点是我们要删除的单词的最后一个字符
    if (index == word.size() - 1) {
        // 如果当前节点是叶子节点，直接删除
        if (isLeaf(node->children[charIndex])) {
            node->children[charIndex] = nullptr;
        } else { // 如果不是叶子节点，移除单词结束标记
            node->children[charIndex]->is_end = false;
        }
    }

    // 如果当前字符对应的子树为空（没有子节点或都是叶子节点），则删除该子树
    if (node->children[charIndex] == nullptr && index == 0) {
        delete node; // 注意这里需要使用引用传递的node
        node = nullptr;
    }
}

// 调用删除函数
void deleteWordFromTrie(Node *root, string word) {
    deleteWord(root, word);
}

int main() {
    Trie *tree = new Trie();
    tree->insert("apple");
    cout << tree->search("apple") << endl;
    cout << tree->startsWith("app") << endl;

    deleteWord(tree->root, "apple");
    cout << tree->search("apple") << endl;

    return 0;
}