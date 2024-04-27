/*************************
 * @file   : 10_change.cpp
 * @encode : UTF-8
 * @note   : 柠檬水找零 https://leetcode.cn/problems/lemonade-change/description/
 * @date   : 2024/4/15 14
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/* 有如下三种情况：
 * 情况一：账单是5，直接收下。
 * 情况二：账单是10，消耗一个5，增加一个10
 * 情况三：账单是20，优先消耗一个10和一个5，如果不够，再消耗三个5
 */
/* 因为美元10只能给账单20找零，而美元5可以给账单10和账单20找零，美元5更万能！
 * 所以局部最优：遇到账单20，优先消耗美元10，完成本次找零
 */

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int m_5 = 0, m_10 = 0, m_20 = 0;
        for (int i = 0; i < bills.size(); ++i) {
            int cur_m = bills[i];
            if (cur_m == 5) {
                m_5++;
            } else if (cur_m == 10) {
                m_5--;
                m_10++;
            } else {  // 20 面额
                if (m_10 > 0) {  // 有 10元优先使用
                    m_10--;
                    m_5--;
                } else {
                    m_5 -= 3;
                }
                m_20++;
            }
            if (m_5 < 0 || m_10 < 0 || m_20 < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};

    Solution so;

    cout << so.lemonadeChange(bills) << endl;

    return 0;
}