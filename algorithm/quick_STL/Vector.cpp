#include <iostream>
#include <vector>

using namespace std;

/*
 * .size() 数组长度
 * .clear() 清空数组
 * .empty() 数组是否为空
 * .begin() 首元素的迭代器
 * .end() 尾元素的迭代器
 *
 * .erase() 删除数组某个迭代器所在位置的数据
 * .push_back() 往数组后面添加元素
 * .pop_back() 删除数组最后一个元素
 */

int main() {

    vector<int> new_vec = {0, 10, 100, 1000, 10000};
    cout << new_vec[2] << endl;

    vector<int> vec(100);
    vec.push_back(101);
    vec.push_back(102);

    cout << vec.size() << endl;

    vec.pop_back();
    cout << vec.size() << endl;

    // 迭代器，在STL中指的其实就是指针，使用方法也和指针一样
    vector<int>::iterator vec2 = vec.end();
    cout << *vec2 << endl;
    vec2 -= 1;
    cout << *vec2 << endl;

    /* iterator erase(iterator position);
        删除position指向的元素，返回指向被删除元素之后的元素的迭代器。
     * iterator erase(iterator first, iterator last);
        删除[first, last)范围内的元素，返回指向被删除元素之后的元素的迭代器。
      void erase(iterator first, iterator last);
        删除[first, last)范围内的元素，不返回任何值。
     */
    cout << "===== erase =====" << endl;
    cout << vec.size() << " " << *vec.end() << endl;
    vec.erase(vec.end() - 1);
    cout << vec.size() << " " << *vec.end() << endl;


    return 0;
}

