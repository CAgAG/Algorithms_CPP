
#include "DoubleLinkNode.h"

int main(){

    DLNode *list = (DLNode *) malloc(sizeof(DLNode));
    list->prior = nullptr;
    list->next = nullptr;

    Insert(list);
    print_list(list);

    printf("\n");
    EleType data = Delete(list, 2);
    printf("\ndelete data: %d\n", data);
    print_list(list);

    return 0;
}

