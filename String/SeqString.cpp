
#include "SeqString.h"

void InitString(SeqString &Str) {
    clear(Str);
    Str->length = 0;
}

int StrLength(SeqString Str) {
    int length = 0;
    for (length = 0; Str->ch[length] != '\0'; length++) {}
    return length;
}

void StrConcat(SeqString &Str1, SeqString Str2) {
    for (int i = 0; i < Str2->length; ++i) {
        Str1->ch[Str1->length++] = Str2->ch[i];
    }
    Str1->ch[Str1->length] = '\0';
}


bool StrCompare(SeqString S1, SeqString S2) {
    int min_length = S1->length;
    if (min_length != S2->length) {
        return false;
    }
    for (int i = 0; i < min_length; ++i) {
        if (S1->ch[i] != S2->ch[i]) {
            return false;
        }
    }
    return true;
}

bool SubString(SeqString &Sub, SeqString Str, int pos, int len) {
    if ((pos + len) > Str->length) {
        return false;
    }
    for (int i = pos, j = 0; i < pos + len; ++i, ++j) {
        Sub->ch[j] = Str->ch[i];
    }
    Sub->length = len;
    Sub->ch[len] = '\0';
    return true;
}

void print_string(SeqString Str) {
    printf("\n");
    for (int i = 0; i < Str->length; ++i) {
        printf("%c", Str->ch[i]);
    }
    printf("\n");
}

void clear(SeqString &S) {
    S->length = 0;
    memset(S->ch, '\0', sizeof(S->ch));
}

int Index(SeqString S1, SeqString S2) {
    SeqString sub = (SeqString) malloc(sizeof(SString));
    int i = 0, n = StrLength(S1), m = StrLength(S2);
    while (i <= n - m + 1) {
        clear(sub);
        SubString(sub, S2, i, m - i);
        if (StrCompare(sub, S2)) ++i;
        else return i;
    }
    return 0;
}

int SimplePart(SeqString S, SeqString T) {
    int i = 1, j = 1;
    while (i < S->length && j < T->length) {
        if (S->ch[i] == T->ch[j]) {
            ++i, ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T->length) return i - T->length;
    return 0;
}


void prefix_table(SeqString T, int prefix[]) {
    // 第1个字符已知为0, 忽略
    int len = 0;
    prefix[0] = len;
    // 从第二个字符开始比较
    int i = 1;
    while (i < T->length) {
        // 下一位如果与当前位相等
        if (T->ch[i] == T->ch[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if (len > 0) {
                // 斜左下角的prefix
                len = prefix[len - 1];
            } else {
                // 无法再后退
                prefix[i] = 0;
                i++;
            }
        }
    }
}

// 向前移动一位, 第一位填充为-1  --> 仅为了后面KMP算法的实现
void move_prefix_table(int prefix[], int length) {
    for (int i = length - 1; i > 0; --i) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

void KMP_search(SeqString text, SeqString pattern) {
    int p_len = pattern->length;
    int t_len = text->length;

    int *prefix = (int *) malloc(sizeof(int) * p_len);

    prefix_table(pattern, prefix);
    move_prefix_table(prefix, p_len);

    // i --> text
    // j --> pattern
    int i = 0, j = 0;
    while (i <= t_len){
        if (j == p_len){
            // 全匹配
            printf("found pattern at %d\n", i - p_len);
            // 继续往后匹配, 根据实际要求也可以直接退出
            j = prefix[j];
        }

        if (text->ch[i] == pattern->ch[j]){
            i++, j++;
        } else {
            j = prefix[j];
            // 第一位都不匹配, 已经无法后退
            if (j == -1){
                i++, j++;
            }
        }
    }

}