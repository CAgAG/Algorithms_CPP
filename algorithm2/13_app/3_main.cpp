/*************************
 * @file   : 3_main.cpp
 * @encode : UTF-8
 * @note   : 平衡二叉搜索树实现 测试
 * @date   : 2024/6/2 11
 *************************/

#include "3_AVL_tree.cpp"
#include "iostream"

using namespace std;


int main() {
    AVLTree *tree = new AVLTree();

    for (int i = 0; i < 6; ++i) {
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