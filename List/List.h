#define MaxSize 50
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

// 插入操作
bool ListInsert(SeqList &L, int i, ElemType e);

// 删除操作
bool ListDelete(SeqList &L, int i, ElemType &e);

// 顺序查找
int LocateElem(SeqList L, ElemType e);

// ========================================
// 删除最小值(假设唯一), 并返回删除的值, 空出的元素由最后一个元素填补
bool DeleteMinElem(SeqList &L, ElemType &e);

// 顺序表逆序
void Reverse(SeqList &L);

// 删除元素
void DeleteValue(SeqList &L, ElemType e);
