/*************************
 * @file   : 1_.cpp
 * @encode : UTF-8
 * @note   : 阶乘后的零 https://leetcode.cn/problems/factorial-trailing-zeroes/description/
 * @date   : 2024/6/28 10
 *************************/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/* https://leetcode.cn/problems/factorial-trailing-zeroes/solutions/47030/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/?envType=study-plan-v2&envId=top-interview-150
 * 再具体对于 5!，也就是 5 * 4 * 3 * 2 * 1 = 120，我们发现结果会有一个 0，原因就是 2 和 5 相乘构成了一个 10。
 * 而对于 10 的话，其实也只有 2 * 5 可以构成，所以我们只需要找有多少对 2*5。
 * 我们把每个乘数再稍微分解下
 *    a. 对于含有 2 的因子的话是 1 * 2, 2 * 2, 3 * 2, 4 * 2 ...
 *    b. 对于含有 5 的因子的话是 1 * 5, 2 * 5...
 * 含有 2 的因子每两个出现一次，含有 5 的因子每 5 个出现一次，所有 2 出现的个数远远多于 5，
 * 换言之找到一个 5，一定能找到一个 2 与之配对。所以我们只需要找有多少个 5。
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            int cur_num = i;
            // 只需要判断每个累乘的数有多少个 5 的因子即可
            while (cur_num > 0) {  // 不能是 0
                if (cur_num % 5 == 0) {
                    ret++;
                    cur_num /= 5;
                } else {
                    break;
                }
            }
        }
        return ret;
    }

    // 优化: 规律就是每隔 5 个数，出现一个 5，每隔 25 个数，出现 2 个 5，每隔 125 个数，出现 3 个 5... 以此类推。
    int trailingZeroes2(int n) {
        int ret = 0;
        int f = 5;

        while (f <= n) {
            ret += n / f;
            f *= 5;
        }

        return ret;
    }

    // 分母可能会造成溢出, 先把 n 更新，n = n / 5
    int trailingZeroes3(int n) {
        int ret = 0;

        while (n > 0) {
            ret += n / 5;
            n /= 5;
        }

        return ret;
    }

};

int main() {

    Solution so;
    cout << so.trailingZeroes(10) << endl;

    return 0;
}