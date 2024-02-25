/*************************
 * @file   : chicken.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/13 15
 *************************/

/* 百钱买百鸡问题
 * 有一个人有一百块钱，打算买一百只鸡。
 * 公鸡一只3元,母鸡一只5元,小鸡3只1元
 * 试求用100元买100只鸡，各为多少才合适？输出所有方案 */

#include "vector"
#include "iostream"

using namespace std;

int main() {
    // 去除小鸡的分数, 钱数全部 x3
    const int MG = 9, MM = 15, MX = 1;
    const int MONEY = 300;

    const int TARGET_NUM = 100;

    for (int i = 0; i < MONEY / MX; ++i) {
        int MX_money = i * MX;
        int MX_num = 3 * i;  // 此处的数量应该是3倍

        if (MX_num > TARGET_NUM || MX_money > MONEY) {
            break;
        }

        for (int j = 0; j < MONEY / MG; ++j) {
            int MG_money = j * MG;

            if ((MX_num + j) > TARGET_NUM || (MX_money + MG_money) > MONEY) {
                break;
            }

            int k = TARGET_NUM - MX_num - j;  // 直接补充到 TARGET_NUM 只鸡
            int MM_money = k * MM;

            if ((MX_money + MG_money + MM_money) > MONEY) {
                continue;
            }
            // 输出结果
            cout << "gj: " << k << " | ";
            cout << "mj: " << j << " | ";
            cout << "xj: " << MX_num << " | " << endl;

        }
    }

    return 0;
}

/* 更加快的方法
 * 设方程:
 *      3X + 5Y + Z/3 = 100;
 *      X+Y+Z=100;
 * for枚举x,把x看作已知，解出y, z
 * 5Y+Z/3 = 100-3X ==> Y = (200-8X)/14
 * Y+Z    = 100-X  ==> Z = (1200-6X)/14
 */
