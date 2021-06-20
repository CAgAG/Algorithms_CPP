#include <stdio.h>
#include <stdlib.h>

#define EleType int

typedef struct DLNode{
    EleType data;
    struct DLNode *prior, *next;
} DLNode, *DLinkNode;

// 插入
DLNode *Insert(DLinkNode &L);

// 删除
EleType Delete(DLinkNode &L, int i);

// 打印链表
void print_list(DLinkNode &L);