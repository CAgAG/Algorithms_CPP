/*************************
 * @file   : 7_top_k_freq_num.cpp
 * @encode : UTF-8
 * @note   : 前 K 个高频元素 https://leetcode.cn/problems/top-k-frequent-elements/description/
 * @date   : 2024/3/8 10
 *************************/

#include "iostream"
#include "stack"
#include "deque"
#include "queue"
#include "string"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        if (nums.size() < 2) {
            return nums;
        }

        map<int, int> num_count;
        for (int num: nums) {
            num_count[num]++;
        }

        priority_queue<pair<int, int>> pque;   // 默认对第一位 从大到小排序
        // 使用大顶堆就要把所有元素都进行排序
        for (auto m: num_count) {
            int num = m.first;
            int count = m.second;

            pque.push({count, num});
        }

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(pque.top().second);
            pque.pop();
        }
        return ret;
    }

    /* ============================================= */
    // 小顶堆
    class my_comparison {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent2(vector<int> &nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, my_comparison> pque;

        // 用固定大小为 k的小顶堆，扫面所有频率的数值
        for (auto it = map.begin(); it != map.end(); it++) {
            pque.push(*it);
            if (pque.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pque.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = pque.top().first;
            pque.pop();
        }
        return ret;
    }
};

int main() {
    vector<int> tokens = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution so;

    for (auto a: so.topKFrequent(tokens, k)) {
        cout << a << " ";
    }
    cout << endl;

    for (auto a: so.topKFrequent2(tokens, k)) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}