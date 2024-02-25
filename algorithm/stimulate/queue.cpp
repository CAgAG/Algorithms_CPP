/*************************
 * @file   : queue.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/2/12 21
 *************************/

/* 给定两个输入，分别表示用户的输出和正确的输出，你来模拟测评机，对两个输出进行比较。
 * 完全相同输出“Accepted”
 * 只有空格，tab，回车的不同，输出“Presentation Error”
 * 否则输出“WrongAnswer"
 */

#include "queue"
#include "string"
#include "iostream"

using namespace std;

bool check(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int main() {
    const string IN_1 = "   1 +2 = 3 ";
    const string IN_2 = "  1 + 2 = 3 ";

    bool AP_flag = true;

    queue<char> ans_1;
    for (int i = 0; i < IN_1.size(); ++i) {
        ans_1.push(IN_1[i]);
    }
    queue<char> ans_2;
    for (int i = 0; i < IN_2.size(); ++i) {
        ans_2.push(IN_2[i]);
    }

    while (!ans_1.empty()) {
        char a1 = ans_1.front();
        char a2 = ans_2.front();

        if (a1 != a2) {
            AP_flag = false;

            bool a1_flag = check(a1);
            bool a2_flag = check(a2);
            if (!a1_flag && !a2_flag) {
                cout << "Wrong Answer" << endl;
                return 0;
            }
            if (a1_flag) {
                ans_1.pop();
            }
            if (a2_flag) {
                ans_2.pop();
            }
        } else {
            ans_1.pop();
            ans_2.pop();
        }

    }

    if (AP_flag) {
        cout << "Accepted" << endl;
    } else {
        cout << "Presentation Error" << endl;
    }


    return 0;
}
