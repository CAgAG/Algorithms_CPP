#include "LinkNode_Queue.h"

int main(){
    EleType data;

    LQueue *queue = (LQueue *) malloc(sizeof(LQueue));
    InitQueue(queue);
    printf("\n%d\n", IsEmpty(queue));

    for (int i = 0; i < 5; ++i) {
        EnQueue(queue, i);
    }
    print_queue(queue);

    DeQueue(queue, data);
    print_queue(queue);
    printf("\ndelete data: %d\n", data);

    return 0;
}

