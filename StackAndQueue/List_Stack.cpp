
#include "List_Stack.h"

void InitStack(SeqStack &S) {
    S->top = -1;
}

bool StackEmpty(SeqStack S) {
    if (S->top == -1) {
        return true;
    }
    return false;
}

bool Push(SeqStack &S, EleType x) {
    if (S->top == MaxSize - 1) {
        return false;
    }
    S->data[++S->top] = x;
    return true;
}

bool Pop(SeqStack &S, EleType &x) {
    if (S->top == -1) {
        return false;
    }
    x = S->data[S->top--];
    return true;
}

bool GetTop(SeqStack S, EleType &x) {
    if (S->top == -1) {
        return false;
    }
    x = S->data[S->top];
    return true;
}

void print_stack(SeqStack S) {
    printf("\n");
    for (int i = 0; i < S->top + 1; i++) {
        EleType data = S->data[i];
        printf("%d->", data);
    }
    printf("\n");
}