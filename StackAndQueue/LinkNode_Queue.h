#include <stdio.h>
#include <stdlib.h>

#define EleType int

typedef struct LinkNode {
    EleType data;
    struct LinkNode *next;
} LinkNode;

typedef struct LQueue {
    LinkNode *front, *rear;
} *LinkQueue, LQueue;


void InitQueue(LinkQueue &Q);

bool IsEmpty(LinkQueue Q);

void EnQueue(LinkQueue &Q, EleType x);

bool DeQueue(LinkQueue &Q, EleType &x);

void print_queue(LinkQueue Q);




