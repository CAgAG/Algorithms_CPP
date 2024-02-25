/*************************
 * @file   : hash2.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/15 15
 *************************/

/* 出N个数，要求把其中重复的去掉，只保留第一次出现的数。
 * 例如，给出的数为1 2 18 3 3 19 2 3 6 5 4，其中2和3有重复，去除后的结果为1 2 18 3 19 6 5 4。
 * 对于100%的数据，1<=N<=50000，给出的数在32位无符号整数范围内。
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> nums = {
            1, 2, 18, 3, 3, 19, 2, 3, 6, 5, 4
    };

    unordered_map<int, bool> seen;
    vector<int> result;
    for (int num: nums) {
        if (seen.find(num) == seen.end()) {
            result.push_back(num);
            seen[num] = true;
        }
    }

    for (int num: result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

