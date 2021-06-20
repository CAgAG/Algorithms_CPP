
#include "BiTNode.h"

int main() {
    BiTree tree = (BiTree) malloc(sizeof(BiTNode));

    // Init Tree
    BiTree p = tree;
    p->data = -1;

    BiTree tp = (BiTree) malloc(sizeof(BiTNode));
    tp->data = 0;
    p->lchild = tp;

    BiTree tp2 = (BiTree) malloc(sizeof(BiTNode));
    tp2->data = 1;
    tp2->lchild = nullptr;
    tp2->rchild = nullptr;
    p->rchild = tp2;

    p = p->lchild;
    BiTree tp3 = (BiTree) malloc(sizeof(BiTNode));
    tp3->data = 2;
    tp3->lchild = nullptr;
    tp3->rchild = nullptr;
    p->lchild = tp3;

    BiTree tp4 = (BiTree) malloc(sizeof(BiTNode));
    tp4->data = 3;
    tp4->lchild = nullptr;
    p->rchild = tp4;

    BiTree tp5 = (BiTree) malloc(sizeof(BiTNode));
    tp5->data = 4;
    tp5->lchild = nullptr;
    tp5->rchild = nullptr;
    tp4->rchild = tp5;

    // test
    printf("PreOrder\n");
    PreOrder(tree);
    printf("\n");

    printf("PreOrder2\n");
    PreOrder2(tree);
    printf("\n");

    printf("InOrder\n");
    InOrder(tree);
    printf("\n");

    printf("InOrder2\n");
    InOrder2(tree);
    printf("\n");

    printf("PostOrder\n");
    PostOrder(tree);
    printf("\n");

    printf("PostOrder2\n");
    PostOrder2(tree);
    printf("\n");

    printf("LevelOrder\n");
    LevelOrder(tree);
    printf("\n");

    return 0;
}
