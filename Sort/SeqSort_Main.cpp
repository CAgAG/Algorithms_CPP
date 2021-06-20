
#include "SeqSort.h"

int main() {

    EleType list[ListSize];
    int length = 0;
    for (int i = 10, j = 0; i >= 0; --i, ++j) {
        list[j] = i;
        length += 1;
    }

    printf("list: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");

//    InsertSort(list, length);
//    printf("InsertSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

//    Binary_InsertSort(list, length);
//    printf("Binary_InsertSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

//    ShellSort(list, length);
//    printf("ShellSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

//    BubbleSort(list, length);
//    printf("BubbleSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

//    QuickSort(list, 0, length - 1);
//    printf("QuickSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

//    SelectSort(list, length);
//    printf("SelectSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

//    HeapSort(list, length);
//    printf("HeapSort list: ");
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", list[i]);
//    }
//    printf("\n");

    MergeSort(list, 0, length-1);
    printf("MergeSort list: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");


    return 0;
}