#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define EleType int

typedef struct {
    EleType data[MaxSize];
    int front, rear;
} SQ, *SeqQueue;

void InitQueue(SeqQueue &Q);

bool isEmpty(SeqQueue Q);

bool EnQueue(SeqQueue &Q, EleType data);

bool DeQueue(SeqQueue &Q, EleType &data);

void print_queue(SeqQueue Q);
