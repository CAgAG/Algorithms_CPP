#include "List_Queue.h"

int main(){
    EleType data;
    SeqQueue queue = (SeqQueue) malloc(sizeof(SQ));

    InitQueue(queue);
    printf("\n%d\n", isEmpty(queue));

    for (int i = 0; i < 5; ++i) {
        EnQueue(queue, i);
    }
    print_queue(queue);

    DeQueue(queue, data);
    printf("\ndelete data: %d\n", data);
    print_queue(queue);

    return 0;
}

