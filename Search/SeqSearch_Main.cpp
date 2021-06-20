
#include "SeqSearch.h"

int main() {

    SeqList list = (SeqList) malloc(sizeof(SList));
    list->length = 0;
    for (int i = 0; i <= 10; ++i) {
        list->elem[i] = i;
        list->length += 1;
    }
//    for (int i = 10, j = 1; i >= 5; --i, ++j) {
//        list->elem[i] = j;
//    }

    printf("list: ");
    for (int i = 0; i < list->length; ++i) {
        printf("%d ", list->elem[i]);
    }
    printf("\n");

    int pos = Search_Seq(list, 5);
    printf("pos %d value: %d\n", pos, list->elem[pos]);

    pos = Binary_Search(list, 5);
    printf("pos %d value: %d\n", pos, list->elem[pos]);
    return 0;
}

