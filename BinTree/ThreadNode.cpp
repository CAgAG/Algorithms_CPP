
#include "ThreadNode.h"

void visit(ThreadTree T) {
    printf("%d ", T->data);
}

void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != nullptr) {
        InThread(p->lchild, pre);
        // 左子树为空，建立线索
        if (p->lchild == nullptr) {
            p->lchild = pre;
            p->ltag = 1;
        }
        // 建立前驱结点的后继线索
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree &T) {
    ThreadTree pre = nullptr;
    if (T != nullptr) {
        InThread(T, pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}

ThreadTree FirstNode(ThreadTree T) {
    ThreadTree p = (ThreadTree) malloc(sizeof(ThreadNode));
    p = T;
    while (p->ltag == 0) p = p->lchild;
    return p;
}

ThreadTree NextNode(ThreadTree T) {
    ThreadTree p = (ThreadTree) malloc(sizeof(ThreadNode));
    p = T;
    if (p->rtag == 0) return FirstNode(p->rchild);
    return p->rchild;
}

void InOrder(ThreadTree T) {
    for (ThreadTree p = FirstNode(T); p != nullptr; p = NextNode(p)) {
        visit(p);
    }
}
