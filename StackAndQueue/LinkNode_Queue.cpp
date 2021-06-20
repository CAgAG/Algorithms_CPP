
#include "LinkNode_Queue.h"


void InitQueue(LinkQueue &Q) {
    Q->front = Q->rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q->front->next = nullptr;
}

bool IsEmpty(LinkQueue Q) {
    if (Q->front == Q->rear) return true;
    return false;
}

void EnQueue(LinkQueue &Q, EleType x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    Q->rear->next = s;
    Q->rear = s;
}

bool DeQueue(LinkQueue &Q, EleType &x) {
    if (IsEmpty(Q)) return false;
    LinkNode *p = Q->front->next;
    x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return true;
}

void print_queue(LinkQueue Q){
    printf("\n");
    LinkNode *p = Q->front->next;
    while (p != nullptr){
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}