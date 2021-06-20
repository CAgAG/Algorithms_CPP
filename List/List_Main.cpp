#include "List.h"
#include "iostream"

using namespace std;

int main() {
    SeqList L;
    L.length = 0;

    ElemType e;
    int i = 0;
    while (cin >> e) {
        if (e == -1) {
            break;
        }
        ListInsert(L, i, e);
        i++;
    }

    for (int j = 0; j < L.length; ++j) {
        cout << L.data[j] << ' ';
    }
    cout << endl;

    ElemType delete_Data;
    ListDelete(L, 0, delete_Data);
    cout << "delete data: " << delete_Data << endl;
    for (int j = 0; j < L.length; ++j) {
        cout << L.data[j] << ' ';
    }
    cout << endl;

    ListDelete(L, 2, delete_Data);
    cout << "delete data: " << delete_Data << endl;
    for (int j = 0; j < L.length; ++j) {
        cout << L.data[j] << ' ';
    }
    cout << endl;

    int index = LocateElem(L, 3);
    cout<< index << ": " << L.data[index] << endl;

    Reverse(L);
    DeleteValue(L, 2);
    for (int j = 0; j < L.length; ++j) {
        cout << L.data[j] << ' ';
    }
    cout << endl;
    DeleteMinElem(L, delete_Data);
    cout<< delete_Data << endl;

    return 0;
}

