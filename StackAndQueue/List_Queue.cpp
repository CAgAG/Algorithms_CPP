
#include "List_Queue.h"

void InitQueue(SeqQueue &Q){
    Q->front = Q->rear = 0;
}

bool isEmpty(SeqQueue Q){
    if (Q->front == Q->rear) return true;
    return false;
}

bool EnQueue(SeqQueue &Q, EleType data){
    if ((Q->rear + 1) % MaxSize == Q->front){
        return false;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SeqQueue &Q, EleType &data){
    if (isEmpty(Q)) return false;
    data = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}

void print_queue(SeqQueue Q){
    printf("\n");
    int i = Q->front;
    while (i != Q->rear){
        printf("%d->", Q->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("\n");
}