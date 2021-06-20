#include <stdio.h>
#include <stdlib.h>

#define EleType int
#define MAXSIZE 50

typedef struct BiTNode {
    EleType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree tree);

void PreOrder(BiTree &T);

void InOrder(BiTree &T);

void PostOrder(BiTree &T);

typedef struct {
    BiTree data[MAXSIZE];
    int top;
} SStack, *SeqStack;

void InitStack(SeqStack &S);

bool IsEmpty_Stack(SeqStack S);

bool Push(SeqStack &S, BiTNode* x);

bool Pop(SeqStack &S, BiTree &x);

bool GetTop(SeqStack &S, BiTree &x);

void PreOrder2(BiTree &T);

void InOrder2(BiTree &T);

void PostOrder2(BiTree &T);

typedef struct {
    BiTree data[MAXSIZE];
    int front, rear;
} SQ, *SeqQueue;

void InitQueue(SeqQueue &Q);

bool IsEmpty_Queue(SeqQueue Q);

bool EnQueue(SeqQueue &Q, BiTree data);

bool DeQueue(SeqQueue &Q, BiTree &data);

void LevelOrder(BiTree &T);
