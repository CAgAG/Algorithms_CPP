/*************************
 * @file   : 4_main.cpp
 * @encode : UTF-8
 * @note   : 红黑树实现 测试
 * @date   : 2024/6/2 22
 *************************/

#include "4_RedBlackTree.cpp"
#include "iostream"

using namespace std;

// 0: 红色, 1: 黑色

int main() {
    RBTree *tree = new RBTree();

    for (int i = 0; i < 10; ++i) {
        tree->Insert(i);
    }

    cout << "in traversal ====================" << endl;
    tree->InOrderPrint(tree->GetRoot());
    cout << endl << "in traversal ====================" << endl;

    tree->Delete(5);
    cout << "in traversal ====================" << endl;
    tree->InOrderPrint(tree->GetRoot());
    cout << endl << "in traversal ====================" << endl;

    tree->Delete(3);
    cout << "in traversal ====================" << endl;
    tree->InOrderPrint(tree->GetRoot());
    cout << endl << "in traversal ====================" << endl;

    tree->Insert(5);
    cout << "in traversal ====================" << endl;
    tree->InOrderPrint(tree->GetRoot());
    cout << endl << "in traversal ====================" << endl;

    tree->Insert(3);
    cout << "in traversal ====================" << endl;
    tree->InOrderPrint(tree->GetRoot());
    cout << endl << "in traversal ====================" << endl;


    return 0;
}