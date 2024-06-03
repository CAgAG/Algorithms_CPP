/*************************
 * @file   : 5_hash_link.cpp
 * @encode : UTF-8
 * @note   : 散列表; 拉链法实现
 * @date   : 2024/6/3 21
 *************************/

#include "string"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct node {
    string key;
    int data;

    node *next;

    node() {
        next = nullptr;
    }
};

class HashTable {
public:
    HashTable(int);

    int hash_key(string);

    bool insert(string, int);

    bool remove(string);

    node *get(string);

    void print();

private:
    int div;
    int size;
    vector<node *> list;
};

HashTable::HashTable(int i_div) {
    div = i_div;
    size = 0;
    list = vector<node *>();
    for (int i = 0; i < div; ++i) {
        list.push_back(nullptr);
    }
}

int HashTable::hash_key(string key) {
    int sum = 0;
    for (int i = 0; i < key.size(); ++i) {
        sum += key[i];
    }
    return sum % div;
}

node *HashTable::get(string key) {
    int f_index = hash_key(key);
    node *cur_node = list[f_index];

    while (cur_node != nullptr) {
        if (cur_node->key == key) {
            return cur_node;
        }
        cur_node = cur_node->next;
    }
    return nullptr;
}

bool HashTable::insert(string key, int data) {
    // 查找
    int f_index = hash_key(key);
    node *cur_node = list[f_index];

    // 构造数据
    node *tail_node = new node();
    tail_node->key = key;
    tail_node->data = data;

    if (cur_node == nullptr) {
        list[f_index] = tail_node;
        size++;
        return true;
    }

    node *pre_node = nullptr;
    while (cur_node != nullptr) {
        if (cur_node->key == key) {  // key 冲突
            return false;
        }
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    size++;
    pre_node->next = tail_node;
    return true;
}

bool HashTable::remove(string key) {
    // 查找
    int f_index = hash_key(key);
    node *cur_node = list[f_index];

    node *pre_node = nullptr;
    while (cur_node != nullptr) {
        if (cur_node->key == key) {
            if (pre_node == nullptr) {
                list[f_index] = cur_node->next;
            } else {
                pre_node->next = cur_node->next;
            }
            size--;
            return true;
        }
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    return false;
}

void HashTable::print() {
    cout << "============== list" << endl;
    for (int i = 0; i < list.size(); ++i) {
        node *cur_node = list[i];
        while (cur_node != nullptr) {
            cout << "(" << cur_node->key << ", " << cur_node->data << ") ";
            cur_node = cur_node->next;
        }
        cout << endl;
    }
    cout << "============== list" << endl;
}

int main() {
    HashTable *ht = new HashTable(5);

    for (int i = 0; i < 5; ++i) {
        string key = "key_" + to_string(i);
        ht->insert(key, i);
    }

    ht->print();

    cout << "key remove" << endl;
    cout << ht->remove("key_1") << endl;

    cout << "key err" << endl;
    cout << ht->insert("key_1", 1) << endl;

    cout << "key remove" << endl;
    cout << ht->remove("key_1") << endl;

    cout << "key insert" << endl;
    cout << ht->insert("key_1", 10) << endl;

    cout << "key get" << endl;
    node *get_data = ht->get("key_1");
    if (get_data != nullptr) {
        cout << get_data->data << endl;
    } else {
        cout << "not find" << endl;
    }

    ht->print();
}