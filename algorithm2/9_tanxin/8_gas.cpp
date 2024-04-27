/*************************
 * @file   : 8_gas.cpp
 * @encode : UTF-8
 * @note   : 加油站 https://leetcode.cn/problems/gas-station/description/
 * @date   : 2024/4/14 11
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int ret = -1;
        for (int start_index = 0; start_index < gas.size(); ++start_index) {
            int car_gas = 0;
            bool first_flag = true;
            for (int i = start_index; i < gas.size(); i %= gas.size()) {
                // 可达
                if (!first_flag && i == start_index) {
                    ret = start_index;
                    break;
                }
                int cur_gas = gas[i];
                int cur_cost = cost[i];

                car_gas += cur_gas;
                // 不够
                if (car_gas < cur_cost) {
                    break;
                }
                car_gas -= cur_cost;
                first_flag = false;
                i++;
            }
            if (ret != -1) {
                return ret;
            }
        }
        return ret;
    }

    // 全局贪心
    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
        int curSum = 0;
        int min_v = INT_MAX; // 从起点出发，油箱里的油量最小值
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i];  // 一天剩下的油
            curSum += rest;
            if (curSum < min_v) {
                min_v = curSum;
            }
        }

        // 情况一: 如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
        if (curSum < 0) {
            return -1;
        }
        // 情况二: i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。
        if (min_v >= 0) {
            return 0;
        }
        // 情况三: 如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪些节点累加能把这个负数填平，能把这个负数填平的最后一个节点就是出发节点。
        // min_v < 0
        for (int i = gas.size() - 1; i >= 0; --i) {
            int rest = gas[i] - cost[i];  // 一天剩下的油
            min_v += rest;
            if (min_v >= 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};

    Solution so;
    cout << so.canCompleteCircuit(gas, cost) << endl;
    cout << so.canCompleteCircuit2(gas, cost) << endl;

    return 0;
}