/*************************
 * @file   : 2_LFU.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/1 23
 *************************/

// LFU (Least Frequently Used) 是一种缓存淘汰策略，它根据数据项被访问的频率来决定哪些数据项应该被替换。当缓存满时，最不经常使用的数据项（即频率最低的数据项）会被移除。

#include "iostream"
#include "map"
#include "algorithm"
#include "vector"

using namespace std;

struct lfu_data {
    int key;
    int value;
    int count;
};

const int cap = 3;
vector<lfu_data *> freq_data_list = vector<lfu_data *>();
map<int, lfu_data *> cache = map<int, lfu_data *>();


void update_freq(lfu_data *data) {
    int data_index = freq_data_list.size() - 1;
    for (; data_index >= 0; --data_index) {
        if (freq_data_list[data_index] == data) {
            break;
        }
    }
    if (data_index == 0) {
        return;
    }

    int i = data_index;
    for (; i > 0; --i) {
        if (freq_data_list[i - 1]->count <= data->count) {
            freq_data_list[i] = freq_data_list[i - 1];
        } else {
            break;
        }
    }
    freq_data_list[i] = data;
}

int get(int key) {
    if (!cache.empty() && cache.find(key) != cache.end()) {
        cache[key]->count++;
        // TODO: update
        update_freq(cache[key]);
        return cache[key]->value;
    }
    return -1;
}

void set(int key, int value, int count) {
    if (!cache.empty() && cache.find(key) != cache.end()) {
        cache[key]->count++;
        cache[key]->value = value;
        // TODO: update
        update_freq(cache[key]);
        return;
    }

    if (freq_data_list.size() >= cap) {
        cache.erase(freq_data_list.back()->key);
        freq_data_list.pop_back();
    }

    lfu_data *insert_data = new lfu_data{key, value, count};
    freq_data_list.push_back(insert_data);
    cache[key] = insert_data;
}

void print_dque() {
    cout << "print freq_data_list =========================" << endl;
    for (int i = 0; i < freq_data_list.size(); ++i) {
        auto cur_data = freq_data_list[i];
        cout << cur_data->key << ", " << cur_data->value << ", " << cur_data->count << endl;
    }
    cout << "print freq_data_list =========================" << endl;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        set(i, i, 0);
        print_dque();
    }

    cout << "==> get" << endl;
    get(4);
    print_dque();
    get(1);
    print_dque();

    get(0);
    print_dque();

    get(4);
    print_dque();

    set(1, 2, 0);
    print_dque();

    set(1, 2, 0);
    print_dque();

    return 0;
}


