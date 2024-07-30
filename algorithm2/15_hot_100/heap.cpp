/*************************
 * @file   : heap.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/25 21
 *************************/

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

void swap(int &a, int &b) {
    int tp = a;
    a = b;
    b = tp;
}

/**
 * 维护堆的性质
 * @param arr 存储堆的数组
 * @param len 数组长度
 * @param i 待维护节点的下标
 */
void heapify(int arr[], int len, int i) {
    int largest = i;
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;

    if (lson < len && arr[largest] < arr[lson])
        largest = lson;
    if (rson < len && arr[largest] < arr[rson])
        largest = rson;
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, len, largest);
    }
}

// 堆排序入口
void heap_sort(int arr[], int len) {
    int i;
    // 建堆
    // 对非叶节点, 维护. 注意: 堆的节点排序是按层序遍历排序【完全二叉树】; 所以才可以怎么做
    for (i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);

    // 排序: 自底向上
    for (i = len - 1; i > 0; i--) {
        swap(arr[i], arr[0]);  // 交换根节点 和 其他值
        heapify(arr, i, 0);  // 维护根节点: [0| 【,..., i】, |已维护过的]
    }
}

int main() {

    int arr[] = {1, 5, 2, 4, 3};
    heap_sort(arr, 5);

    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}