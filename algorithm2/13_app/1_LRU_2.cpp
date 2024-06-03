/*************************
 * @file   : 1_LRU.cpp
 * @encode : UTF-8
 * @note   : LRU 算法实现
 * @date   : 2024/6/1 22
 *************************/

// LRU（Least Recently Used）算法是一种常用的页面置换算法，用于在缓存中管理数据。当缓存满时，最久未使用的数据项会被移除。

#include "iostream"
#include "list"
#include "map"
#include "algorithm"

using namespace std;

const int cap = 3;
list<pair<int, int>> dque = list<pair<int, int>>();
map<int, pair<int, int>> cache = map<int, pair<int, int>>();


int get(int key) {
    if (!cache.empty() && cache.find(key) != cache.end()) {
        auto it = std::find(dque.begin(), dque.end(), cache[key]);
        dque.erase(it);
        dque.push_front(cache[key]);
        return cache[key].second;
    }
    return -1;
}

void set(int key, int value) {
    if (!cache.empty() && cache.find(key) != cache.end()) {
        auto it = std::find(dque.begin(), dque.end(), cache[key]);
        dque.erase(it);
        cache[key].second = value;
        dque.push_front(cache[key]);
        return;
    }

    if (dque.size() >= cap) {
        int pop_key = dque.back().first;
        cache.erase(cache.find(pop_key));
        dque.pop_back();
    }

    dque.push_front(pair<int, int>(key, value));
    cache[key] = {key, value};
}

void print_dque() {
    cout << "print dque =========================" << endl;
    for (auto it = dque.begin(); it != dque.end(); ++it) {
        cout << it->first << ", " << it->second << endl;
    }
    cout << "print dque =========================" << endl;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        set(i, i);
        print_dque();
    }

    cout << "==> get" << endl;
    get(2);
    print_dque();
    get(4);
    print_dque();

    set(3, 1);
    print_dque();

    return 0;
}
