#include <stdio.h>
#include <stdlib.h>

#define EleType int

typedef struct LNode{
    EleType data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法
LinkList List_HeadInsert(LinkList &L);

// 尾插法
LinkList List_TailInsert(LinkList &L);

// 打印链表
void printList(LinkList &L);

// 查找节点
LNode *GetItem(LinkList &L, int i);

// 按值查找
LNode *LocateElem(LinkList &L, EleType e);

// 插入节点-后插
LNode *Insert_value_tail(LinkList &L, int i, EleType value);

// 插入节点-前插
LNode *Insert_value_head(LinkList &L, int i, EleType value);

// 删除节点
EleType Delete_Node(LinkList &L, int i);