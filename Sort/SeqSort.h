#include <stdio.h>
#include <stdlib.h>

#define EleType int
#define ListSize 11

// 插入排序
void InsertSort(EleType list[], int length);

// 折半插入排序
void Binary_InsertSort(EleType list[], int length);

// 希尔排序
void ShellSort(EleType list[], int length);

// 冒泡排序
void BubbleSort(EleType list[], int length);

// 快速排序
void QuickSort(EleType list[], int low, int high);

// 选择排序
void SelectSort(EleType list[], int length);

// 堆排序
void HeapSort(EleType list[], int length);

// 归并排序
void MergeSort(EleType list[], int low, int high);