#include <stdio.h>
#include <stdlib.h>

#define EleType int

typedef struct ThreadNode {
    EleType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(ThreadTree T);

void InThread(ThreadTree &p, ThreadTree &pre);

void CreateInThread(ThreadTree &T);

ThreadTree FirstNode(ThreadTree T);

ThreadTree NextNode(ThreadTree T);

void InOrder(ThreadTree T);
