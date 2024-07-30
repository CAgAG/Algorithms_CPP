/*************************
 * @file   : 4_.cpp
 * @encode : UTF-8
 * @note   : x 的平方根 https://leetcode.cn/problems/sqrtx/description/
 * @date   : 2024/6/28 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    // 溢出
    int mySqrt(int x) {
        int pre_i = 0;
        for (int i = 0; i <= x; ++i) {

            if (i * i == x) {
                return i;
            }
            if (pre_i * pre_i < x && i * i > x) {
                return pre_i;
            }

            pre_i = i;
        }
        return 0;
    }

    // 防止溢出
    int mySqrt2(int x) {
        if (x == 0) {
            return 0;
        }

        int pre_i = 1;
        for (int i = 1; i <= x; ++i) {

            if (x / i == i) {
                return i;
            }
            if (x / pre_i > pre_i && x / i < i) {
                return pre_i;
            }

            pre_i = i;
        }
        return 0;
    }

    // 二分查找的下界为 0，上界可以粗略地设定为 x。在二分查找的每一步中，
    // 我们只需要比较中间元素 mid 的平方与 x 的大小关系，并通过比较的结果调整上下界的范围。
    // 由于我们所有的运算都是整数运算，不会存在误差，因此在得到最终的答案 ans 后，也就不需要再去尝试 ans+1 了。

};

int main() {
    Solution so;
    cout << so.mySqrt2(8) << endl;
    return 0;
}