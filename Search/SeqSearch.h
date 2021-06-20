#include <stdio.h>
#include <stdlib.h>

#define EleType int
#define MaxSize 50

typedef struct {
    EleType elem[MaxSize];
    int length;
} SList, *SeqList;

int Search_Seq(SeqList &list, EleType key);

int Binary_Search(SeqList &list, EleType key);
