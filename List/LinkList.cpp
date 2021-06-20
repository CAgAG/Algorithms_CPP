//
// Created by aogeChen on 2021/6/13.
//

#include "LinkList.h"

// 头插法
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;
    scanf_s("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf_s("%d", &x);
    }
    return L;
}

// 尾插法
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    // r始终指向链表的尾部
    LNode *s, *r = L;
    scanf_s("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        // r尾接s
        r->next = s;
        // r移动到最后一个节点
        r = s;
        scanf_s("%d", &x);
    }
    r->next = nullptr;
    return L;
}

void printList(LinkList &L) {
    auto *s = (LNode *) malloc(sizeof(LNode));
    s = L->next;
    printf("\n");
    while (s != nullptr) {
        printf("%d->", s->data);
        s = s->next;
    }

}

// 查找节点
LNode *GetItem(LinkList &L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0) {
        return L;
    } else if (i < 0) {
        return nullptr;
    }

    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList &L, EleType e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
    }
    return p;
}

// 插入节点
LNode *Insert_value_tail(LinkList &L, int i, EleType value) {
    LNode *p = GetItem(L, i);
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = value;

    s->next = p->next;
    p->next = s;
    return s;
}

// 插入节点-前插
LNode *Insert_value_head(LinkList &L, int i, EleType value) {
    LNode *p = GetItem(L, i - 1);
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = value;

    s->next = p->next;
    p->next = s;
    return s;
}

// 删除节点
EleType Delete_Node(LinkList &L, int i) {
    LNode *p = GetItem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    EleType data = q->data;
    free(q);
    return data;
}