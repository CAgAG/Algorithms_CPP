#include "SeqString.h"

int main() {

    SeqString string = (SeqString) malloc(sizeof(SString));
    SeqString stp = (SeqString) malloc(sizeof(SString));
    SeqString sub = (SeqString) malloc(sizeof(SString));

    InitString(string);
    InitString(stp);

    for (int i = 0; i < 5; ++i) {
        stp->ch[i] = '0' + i;
    }
    stp->ch[5] = '\0';
    stp->length = 5;

    StrConcat(string, stp);
    print_string(string);

    printf("\nlength: %d\n", StrLength(string));
    printf("\ncompare: %d\n", StrCompare(string, stp));
    SubString(sub, string, 1, 2);
    print_string(sub);

    printf("\nIndex: %d\n", Index(string, stp));

    // pattern
    stp->ch[0] = 'a';
    stp->ch[1] = '\0';
    stp->length = 1;

    // text
    string->ch[0] = 'a';
    string->ch[1] = '\0';
    string->length = 1;

    KMP_search(string, stp);
    return 0;
}

