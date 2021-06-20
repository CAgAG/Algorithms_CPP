#include "List.h"

// 插入操作
bool ListInsert(SeqList &L, int i, ElemType e) {
    if (i < 0 || i >= MaxSize) {
        return false;
    }

    if (L.length >= MaxSize) {
        return false;
    }

    // 移位
    for (int j = L.length; j >= i; --j) {
        L.data[j + 1] = L.data[j];
    }
    L.data[i] = e;
    L.length++;
    return true;
}

// 删除操作
bool ListDelete(SeqList &L, int i, ElemType &e) {
    if (i < 0 || i > L.length + 1) {
        return false;
    }

    e = L.data[i];
    for (int j = i; j < L.length; ++j) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

// 顺序查找
int LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return -1;
}

// ========================================
// 删除最小值(假设唯一), 并返回删除的值, 空出的元素由最后一个元素填补
bool DeleteMinElem(SeqList &L, ElemType &e) {
    if (L.length <= 0) {
        return false;
    }
    ElemType minElem = L.data[0];
    int pos = 0;
    // 找出最小值的位置
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < minElem) {
            minElem = L.data[i];
            pos = i;
        }
    }
    e = L.data[pos];
    ElemType lastElem = L.data[L.length - 1];
    L.data[pos] = lastElem;
    L.length--;
    return true;
}

// 顺序表逆序
void Reverse(SeqList &L) {
    ElemType tp;
    for (int i = 0; i < L.length / 2; ++i) {
        tp = L.data[i];
        L.data[i] = L.data[L.length - 1- i];
        L.data[L.length -1 - i] = tp;
    }
}

// 删除元素
void DeleteValue(SeqList &L, ElemType e){
    int k = 0; // 等于e的个数
    int i = 0;
    while (i < L.length){
        if(L.data[i] == e){
            k++;
        } else{
            L.data[i-k] = L.data[i];
        }
        i++;
    }
    L.length -= k;
}
