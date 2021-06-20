
#include "BiTNode.h"

void visit(BiTree tree) {
    if (tree != nullptr) {
        printf("%d ", tree->data);
    } else {
        printf("null ");
    }
}

void PreOrder(BiTree &T) {
    if (T != nullptr) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree &T) {
    if (T != nullptr) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree &T) {
    if (T != nullptr) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// stack

void InitStack(SeqStack &S) {
    S->top = -1;
}

bool IsEmpty_Stack(SeqStack S) {
    if (S->top == -1) {
        return true;
    }
    return false;
}

bool Push(SeqStack &S, BiTNode *x) {
    if (S->top == MAXSIZE - 1) {
        return false;
    }
    S->data[++S->top] = x;
    return true;
}

bool Pop(SeqStack &S, BiTree &x) {
    if (S->top == -1) {
        return false;
    }
    x = S->data[S->top--];
    return true;
}

bool GetTop(SeqStack &S, BiTree &x) {
    if (IsEmpty_Stack(S)) return false;
    x = S->data[S->top];
    return true;
}

void InOrder2(BiTree &T) {
    SeqStack stack = (SeqStack) malloc(sizeof(SStack));
    InitStack(stack);
    BiTree p = T;
    while (p != nullptr || !IsEmpty_Stack(stack)) {
        if (p != nullptr) {
            Push(stack, p);
            p = p->lchild;
        } else {
            Pop(stack, p);
            visit(p);
            p = p->rchild;
        }
    }
}

void PreOrder2(BiTree &T) {
    SeqStack stack = (SeqStack) malloc(sizeof(SStack));
    InitStack(stack);
    BiTree p = T;
    while (p != nullptr || !IsEmpty_Stack(stack)) {
        if (p) {
            visit(p);
            Push(stack, p);
            p = p->lchild;
        } else {
            Pop(stack, p);
            p = p->rchild;
        }
    }
}

void PostOrder2(BiTree &T) {
    SeqStack stack = (SeqStack) malloc(sizeof(SStack));
    InitStack(stack);
    BiTree p = T;
    BiTree r = nullptr;  // 最近访问的结点
    while (p != nullptr || !IsEmpty_Stack(stack)) {
        if (p) {
            Push(stack, p);
            p = p->lchild;
        } else {
            GetTop(stack, p);
            if (p->rchild && p->rchild != r) {  // 右子树存在且未被访问
                p = p->rchild;
                Push(stack, p);
                p = p->lchild;
            } else {
                Pop(stack, p);
                visit(p);
                r = p;  // 记录最近访问的结点
                p = nullptr; // 结点访问完，重置p指针
            }

        }
    }
}

void InitQueue(SeqQueue &Q) {
    Q->front = Q->rear = 0;
}

bool IsEmpty_Queue(SeqQueue Q) {
    if (Q->front == Q->rear) return true;
    return false;
}

bool EnQueue(SeqQueue &Q, BiTree data) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return false;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SeqQueue &Q, BiTree &data) {
    if (IsEmpty_Queue(Q)) return false;
    data = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return true;
}

void LevelOrder(BiTree &T) {
    SeqQueue queue = (SeqQueue) malloc(sizeof(SQ));
    InitQueue(queue);
    BiTree p = nullptr;
    EnQueue(queue, T);
    while (!IsEmpty_Queue(queue)) {
        DeQueue(queue, p);
        visit(p);
        if (p->lchild != nullptr) EnQueue(queue, p->lchild);
        if (p->rchild != nullptr) EnQueue(queue, p->rchild);
    }
}