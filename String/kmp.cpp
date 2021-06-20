/*
KMP算法。（Java中indexOf()方法是凭借KMP算法实现的，可以说KMP是本题最优解）
KMP算法的简明介绍：
https://www.zhihu.com/question/21923021/answer/281346746
https://www.jianshu.com/p/e2bd1ee482c3
 */

#include <string.h>
#include "stdio.h"
#include "stdlib.h"

// 少1
void Next(string pattern, int next[]) {
    int i = 0, j = -1;
    next[i] = j;

    while (i < pattern.size() - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMP(string &text, string &pattern, int next[]) {
    int i = 0, j = 0;
    while (i < text.size() && j < (int) pattern.size()) {
        if (j == -1 || text[i] == pattern[j]) {
            ++i, ++j;
        } else {
            j = next[j];
        }
    }
    if (j == pattern.size())
        return i - pattern.size();
    return 0;
}

int main() {
    string text = "babbabaabcacaabccabcba";
    string str = "abcac";

    const int p_len = 5;
    int next[p_len];
    Next(str, next);
    printf("\nNext: ");
    for (int i : next) {
        printf("%d ", i);
    }
    printf("\n");

    int result = KMP(text, str, next);
    printf("\nresult: %d\n", result);


    return 0;
}



