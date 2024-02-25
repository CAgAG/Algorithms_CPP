/* 题目: 约瑟夫环
 * 内容: 已知 n个人(以编号1，2，3....n分别表示)围坐在一张圆桌周围。
 *      从编号为 1的人开始报数，数到m的那个人出列;
 *      他的下一个人又从 1开始报数，数到 m的那个人又出列;
 *      依此规律重复下去，直到圆桌周围的人全部出列。
 * 输出: 输出出列顺序和最后剩下的人。
 */

#include "vector"
#include "iostream"

using namespace std;

int main() {
    const int N = 9;
    const int M = 3;
    vector<int> desk(N, 1);  // 1为在位, 0为离开

    int cur_m = 0;  // 当前累计的人数
    int loop_i = -1;  // 遍历下标
    int pop_num = 0;  // 离开人数
    while (pop_num < N) {
        loop_i = (loop_i + 1) % N;
        if (desk[loop_i] == 0) {  // 不在位就跳过
            continue;
        }

        cur_m += 1;
        if (cur_m == M) {  // 数到离开的位置
            desk[loop_i] = 0;  // 状态转为 0
            cout << loop_i + 1 << " ";  // 输出

            pop_num += 1;  // 离开人数 +1
            cur_m = 0;  // 重新计数
        }
    }

    return 0;
}