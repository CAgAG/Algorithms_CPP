
#include "SeqSearch.h"

int Search_Seq(SeqList &list, EleType key) {
    int i = 0;
    list->elem[i] = key;
    for (i = list->length; list->elem[i] != key; --i);
    return i;
}

int Binary_Search(SeqList &list, EleType key) {
    int low = 0, high = list->length-1 , mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (list->elem[mid] == key) {
            return mid;
        } else if (list->elem[mid] > key) {
            high -= 1;
        } else {
            low += 1;
        }
    }
    return -1;
}