/*************************
 * @file   : stand.cpp
 * @encode : UTF-8
 * @note   : 维护一个从栈底到栈顶 单调递减的栈
 * @date   : 2024/2/14 12
 *************************/

/* 有n个人站队，所有的人全部向右看，个子高的可以看到个子低的人发型（高个子会挡住低个子的视线，这里的身高大于是严格大于）
 * 给出每个人的身高，问所有人能看到其他人发型数量的总和是多少。
 * 输入：4 3 7 1
 * 输出：2
 * 解释：个子为4的可以看到个子为3的发型（因为被7挡住所以看不到1），个子为7可以看到个子为1的身高，所以1+1=2
 * =============================
 * 将问题转换为当前人能否被左边的人看见
 */

#include "stack"
#include "iostream"

using namespace std;

int main() {
    int Q[] = {7, 3, 4, 1};
    stack<int> dec_stack;
    int looked_count = 0;

    for (int i = 0; i < size(Q); ++i) {
        int cur_h = Q[i];

        while (!dec_stack.empty() && dec_stack.top() < cur_h) {  // 维护单调递减的栈
            dec_stack.pop();
        }

        looked_count += dec_stack.size();
        dec_stack.push(cur_h);
    }
    cout << looked_count << endl;

    return 0;
}