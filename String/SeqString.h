#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} *SeqString, SString;

void InitString(SeqString &Str);

int StrLength(SeqString Str);

bool StrCompare(SeqString S1, SeqString S2);

bool SubString(SeqString &Sub, SeqString Str, int pos, int len);

void print_string(SeqString Str);

void StrConcat(SeqString &Str1, SeqString Str2);

int Index(SeqString S1, SeqString S2);

void clear(SeqString &S);

int SimplePart(SeqString S, SeqString T);

void prefix_table(SeqString T, int prefix[]);

void move_prefix_table(int prefix[], int length);

void KMP_search(SeqString text, SeqString pattern);