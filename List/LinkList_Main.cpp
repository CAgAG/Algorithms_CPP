#include "LinkList.h"

int main(){

    auto *list = (LNode *) malloc(sizeof(LNode));
//    List_HeadInsert(list);
    List_TailInsert(list);
    printList(list);

    printf("\n%d", GetItem(list, 3)->data);
    printf("\nindex: %d\n", LocateElem(list, 3)->data);
    Insert_value_tail(list, 2, 100);
    printList(list);
    Delete_Node(list, 2);
    printList(list);
    return 0;
}

