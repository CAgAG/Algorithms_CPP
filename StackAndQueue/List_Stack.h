#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define EleType int

typedef struct {
    EleType data[MaxSize];
    int top;
} SStack, *SeqStack;

void InitStack(SeqStack &S);

bool StackEmpty(SeqStack S);

bool Push(SeqStack &S, EleType x);

bool Pop(SeqStack &S, EleType &x);

bool GetTop(SeqStack S, EleType &x);

void print_stack(SeqStack S);


