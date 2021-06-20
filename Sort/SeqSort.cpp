
#include "SeqSort.h"

void InsertSort(EleType list[], int length) {
    int j;
    EleType tp;
    for (int i = 1; i <= length; ++i) {
        if (list[i] < list[i - 1]) {
            tp = list[i];
            // 找到已排序序列的插入位置
            for (j = i - 1; list[0] < list[j]; --j) {
                list[j + 1] = list[j];
            }
            list[j + 1] = tp;
        }
    }
}

void Binary_InsertSort(EleType list[], int length) {
    int i, j, low, high, mid;
    EleType tp;
    for (i = 1; i <= length; ++i) {
        tp = list[i];
        low = 1, high = i - 1;
        // 对已排序的序列进行折半查找
        while (low <= high) {
            mid = (low + high) / 2;
            if (list[mid] > list[0]) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; --j) {
            list[j + 1] = list[j];
        }
        list[high + 1] = tp;
    }
}

void ShellSort(EleType list[], int length) {
    int j;
    EleType tp;
    for (int dk = length / 2; dk >= 1; dk = dk / 2) {
        for (int i = dk; i < length; ++i) {
            if (list[i] < list[i - dk]) {
                tp = list[i];
                for (j = i - dk; j >= 0 && tp < list[j]; j -= dk) {
                    list[j + dk] = list[j];
                }
                list[j + dk] = tp;
            }
        }
    }
}

void BubbleSort(EleType list[], int length) {
    bool flag;
    EleType tp;
    for (int i = 0; i < length - 1; ++i) {
        flag = false;
        for (int j = length - 1; j > i; --j) {
            if (list[j - 1] > list[j]) {
                tp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = tp;
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}


int Partition(EleType list[], int low, int high) {
    EleType pivot = list[low];
    while (low < high) {
        while (low < high && list[high] > pivot) --high;
        // 把比pivot值小的移到左边
        list[low] = list[high];
        while (low < high && list[low] <= pivot) ++low;
        // 把比pivot值大的移到右边
        list[high] = list[low];
    }
    list[low] = pivot;
    return low;
}


void QuickSort(EleType list[], int low, int high) {
    if (low < high) {
        int pivot_pos = Partition(list, low, high);
        QuickSort(list, low, pivot_pos - 1);
        QuickSort(list, pivot_pos + 1, high);
    }
}

void SelectSort(EleType list[], int length) {
    int min;
    EleType tp;
    for (int i = 0; i < length - 1; ++i) {
        min = i;
        for (int j = i + 1; j < length; ++j) {
            if (list[j] < list[min]) min = j;
        }
        if (min != i) {
            tp = list[i];
            list[i] = list[min];
            list[min] = tp;
        }
    }
}

void HeapAdjust(EleType list[], int k, int length) {
    EleType tp;
    tp = list[k];
    for (int i = 2 * k; i <= length; i *= 2) {
        // 取key较大的结点向下筛选
        if (i < length && list[i] < list[i + 1]) i++;
        // 筛选结束
        if (tp >= list[i]) break;
        else {
            // 将list[i]调整到双亲结点上
            list[k] = list[i];
            // 继续向下筛选
            k = i;
        }
    }
    list[k] = tp;
}

void BuildMaxHeap(EleType list[], int length) {
    for (int i = length / 2, j = 0; i > 0; --i, ++j) {
        HeapAdjust(list, i, length);

        printf("No.%d HeapAdjust\n", j);
        for (int k = 0; k < length; ++k) {
            printf("%d ", list[k]);
        }
        printf("\n");

    }
}


void HeapSort(EleType list[], int length) {
    BuildMaxHeap(list, length);

    EleType tp;
    for (int i = length - 1; i > 1; --i) {
        tp = list[i];
        list[i] = list[1];
        list[1] = tp;

        HeapAdjust(list, 1, i - 1);
    }
}

EleType *list2 = (EleType *) malloc((ListSize + 1) * sizeof(EleType));

void Merge(EleType list[], int low, int mid, int high) {
    for (int i = low; i <= high; ++i) {
        list2[i] = list[i];
    }
    int i, j, k;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k) {
        // 比较list2左右两端的元素, 将较小的值复制到list
        if (list2[i] <= list2[j]) list[k] = list2[i++];
        else list[k] = list2[j++];
    }
    // list未检测完, 复制
    while (i <= mid) list[k++] = list2[i++];
    // list2未检测完, 复制
    while (j <= high) list[k++] = list2[j++];
}

void MergeSort(EleType list[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(list, low, mid); // 左序列归并
        MergeSort(list, mid + 1, high); // 右序列归并
        Merge(list, low, mid, high); // 归并
    }
}