
#include "DoubleLinkNode.h"

// 插入
DLNode *Insert(DLinkNode &L) {
    DLNode *s, *p;
    p = L;

    EleType data;
    scanf_s("%d", &data);
    while (data != 9999) {
        s = (DLNode *) malloc(sizeof(DLNode));
        s->data = data;
        s->next = p->next;
        s->prior = p;

        if (p->next != nullptr) {
            p->next->prior = s;
        }

        p->next = s;
        p = s;
        scanf_s("%d", &data);
    }
    return L;
}

// 删除
EleType Delete(DLinkNode &L, int i){
    int j = 1;
    DLNode *p = L;
    DLNode *q = L->next;

    while (p != nullptr && j < i){
        p = q;
        q = p->next;
        j++;
    }
    p->next = q->next;
    q->next->prior = p;

    EleType data = q->data;
    free(q);
    return data;
}

// 打印链表
void print_list(DLinkNode &L) {
    DLNode *p = L->next;
    DLNode *q;

    printf("\nnext link\n");
    while (p != nullptr) {
        printf("%d->", p->data);

        if (p->next == nullptr) {
            q = p;
        }
        p = p->next;
    }

    printf("\nprior link\n");
    while (q->prior != nullptr) {
        printf("%d->", q->data);
        q = q->prior;
    }

}
