/*************************
 * @file   : 3_sort.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/9/7 10
 *************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个比较函数，用于按照 value 从大到小排序，如果 value 相同，则按 key 从大到小排序  
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}

void sortAndPrintKeysByValue(const map<int, int> &m) {
    // 将 map 转换为 vector  
    vector<pair<int, int>> vec(m.begin(), m.end());

    // 使用自定义的比较函数进行排序  
    sort(vec.begin(), vec.end(), compare);

    // 输出排序后的 keys  
    for (const auto &pair: vec) {
        cout << pair.first << " ";
    }
    cout << endl;
}

int main() {
    // 创建一个 map 并插入一些数据  
    map<int, int> m;
    m[1] = 10;
    m[2] = 20;
    m[3] = 15;
    m[4] = 20;
    m[5] = 10;

    // 调用函数进行排序并输出  
    sortAndPrintKeysByValue(m);

    return 0;
}