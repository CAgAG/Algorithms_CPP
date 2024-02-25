#include "iostream"
#include "string"
#include "cstring"
#include "vector"
#include "cstdlib"
#include "cstdio"

#include "algorithm"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#include "complex"  // 复数类
// 以下两个会比正常的 map 和 set 更快一些, 用法一样
#include "unordered_map"
#include "unordered_set"

#include "windows.h"

// #include "bits/stdc++.h"  // 万能头文件, 包含大部分标准库

using namespace std;

void print_list(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_list(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_list(set<int> arr) {
    // set不支持使用小标位置i进行遍历
    for (set<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }

    cout << endl;
}

void print_list(map<string, int> arr) {
    for (std::map<string, int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    cout << endl;
}

// 排序方法
int cmp_func(int a, int b) {
    return a > b;
}

int main() {
    // 支持中文输出
    SetConsoleOutputCP(CP_UTF8);
    string chinese = "你好世界";
    cout << chinese << endl;

    // 排序
    int arr[] = {2, 3, 5, 1, 4};
    vector<int> arr2 {2, 3, 5, 1, 4};
    vector<int> arr3 {2, 3, 5, 1, 4};
    sort(arr, arr + size(arr));
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end(), cmp_func);


    print_list(arr, size(arr));
    print_list(arr2);
    print_list(arr3);

    // 最大，最小值
    cout << max(100, -1) << " " << min(-1, 100) << endl;

    // 最大，最小的元素
    printf("%d %d\n", min_element(arr2.begin(), arr2.end())[0], max_element(arr2.begin(), arr2.end())[0]);

    // 把数组中第 n小 (从0开始算) 的数放到第 n个位置类似快排
    // 此时 n 位置的左边的数比它小，右边的数比它大
    // nth_element（arr.begin(),arr.begin() +n,arr.end());
    int n = 2; // 第3小的数  ==> 因为是从 0开始算的 <== 放到 2 (位置也是从 0开始算) 的位置
    vector<int> arr4 {2, 3, 5, 1, 4};
    nth_element(arr4.begin(), arr4.begin() + n,arr4.end());
    print_list(arr4);

    // 交换元素
    swap(arr2[0], arr2[1]);
    print_list(arr2);

    // 反转数组
    reverse(arr2.begin(), arr2.end());
    print_list(arr2);

    // 唯一值: 必须是排好序的数组才可以达到效果
    // 使数组中重复的元素 放到数组末尾（去重）
    // 返回去重后数组的结束指针
    vector<int> arr5 {1, 1, 2, 2, 3, 3, 4, 4};
    // reverse(arr5.begin(), arr5.end());
    int old_length = arr5.size();
    print_list(arr5);

    int new_length =  unique(arr5.begin(), arr5.end()) - arr5.begin();
    cout << old_length << " ==> " << new_length << endl;
    print_list(arr5);

    // 二分查找: 必须是排好序的数组才可以达到效果且默认从升序
    reverse(arr3.begin(), arr3.end());
    print_list(arr3);
    bool isExist = binary_search(arr3.begin(), arr3.end(), 3);
    cout << isExist << endl;

    // 如果把一个数插入有序数组，它应该插入到哪个位置
    // lower_bound返回第一个插入位置的指针，upper_bound返回最后一个位置的指针
    vector<int> arr6 {1, 1, 2, 2, 3, 3, 4, 4};
    int first_index = lower_bound(arr6.begin(), arr6.end(), 3) - arr6.begin();  // 第一个出现值的位置
    int last_index = upper_bound(arr6.begin(), arr6.end(), 3) - arr6.begin();  // 最后出现值的位置的后面
    cout << first_index << " " << last_index << endl;
    cout << "出现次数: " << last_index - first_index << endl;

    // 栈
    cout << "stack" << endl;
    stack<int> sta;
    sta.push(1);
    sta.push(2);
    sta.push(3);

    int topE = sta.top();
    cout << topE << endl;

    sta.pop();
    topE = sta.top();
    cout << topE << endl;
    // 其他 empty() 和 size() 和 vector类似

    // 队列
    cout << "queue" << endl;
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);

    topE = que.front();
    cout << topE << endl;

    que.pop();
    topE = que.front();
    cout << topE << endl;
    // 其他 empty() 和 size() 和 vector类似

    // 优先队列
    cout << "priority queue" << endl;
    priority_queue<int> pque;
    pque.push(1);
    pque.push(2);
    pque.push(3);

    topE = pque.top();
    cout << topE << endl;

    pque.pop();
    topE = pque.top();
    cout << topE << endl;
    // 其他 empty() 和 size() 和 vector类似

    // 集合
    /* set自带去重，而multiset允许元素重复，通过count可以获得某个元素的数量 */
    set<int> st;
    st.insert(1);
    st.insert(1);
    st.insert(2);

    cout << *st.find(1) << endl;
    print_list(st);
    st.erase(1);
    print_list(st);

    multiset<int> mst;
    mst.insert(1);
    mst.insert(1);
    mst.insert(2);

    cout << mst.count(1) << endl;

    // map映射
    pair<string, int> pa {"年龄1", 100};
    pair<string, int> pa2;
    pa2 = make_pair("项目", 101);

    map<string, int> mp {
            {"年龄0", 99}
    };
    mp["年龄2"] = 102;
    mp.insert(pa);
    mp.insert(pa2);
    print_list(mp);

    mp.erase("项目");
    print_list(mp);

    // 位集合
    /* bitset是一个只由 0和 1构成的数组，其占用空间较小
     * bitset不仅可以和数组一样用下标访问，还可以进行位运算 */
    bitset<8> bst;
    bst[0] = 1;
    bst[1] = 0;

    bst << 1;
    bst >> 1;
    bst ^= 1;
    bst &= 1;
    bst.count(); // 1 的个数
    cout << bst.to_string() << endl;
    cout << bst.to_ulong() << endl;  // 二进制转整数



    return 0;
}


