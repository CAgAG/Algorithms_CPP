/*************************
 * @file   : FT.cpp
 * @encode : UTF-8
 * @note   : 树状数组(Binary Indexed Tree 或 Fenwick Tree)是一种可以高效更新元素并计算前缀和的数据结构.
 *           树状数组的核心思想是利用二进制数的性质来将数组划分为多个小区间，每个区间都可以快速地进行求和和更新操作。
 * @date   : 2024/2/25 14
 *************************/

#include <iostream>
#include <vector>

using namespace std;

// 树状数组实现
class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int n_size){
        n = n_size;
        tree.resize(n + 1, 0); // 树状数组大小需要为原数组大小+1
        // 树状数组的索引是从1开始的，而不是从0开始。这是树状数组实现中的一个常见约定，因为它简化了位运算和区间更新的逻辑。
    }

    // 单点更新：将index位置的元素增加(+)delta
    void update(int index, int delta) {
        while (index <= n) {
            tree[index] += delta;
            index += index & -index; // 相当于index = index + (index & -index); 找到下一个需要更新的位置
        }
    }

    // 计算前缀和：计算从 1到index的元素和
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index; // 相当于index = index - (index & -index); 找到前一个区间
            /* index & -index 的作用是找到 index 的二进制表示中最右边的 1 所对应的值, 即计算的就是 lowbit(index)的值
             *  负数的二进制表示是其正数二进制表示的补码，而补码的特点是最低位的 1 和原数最低位的 1 所处的位置相同，更高位是原数取反后的结果
             *  也就是 负数的补码=正数的反码+1
             *  因此，index & -index 实际上是将 index 中最低位的 1 保留下来，其他位都变为 0
             * 例如 如果 index 的二进制表示是 10100
             *  其-index的补码是 110100，求与后得到 100
             * index 减去这个结果，即 10100 - 100，得到 10000
             */
        }
        return sum;
    }

    // 初始化树状数组，根据原始数组构建
    void build(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i + 1, nums[i]); // 树状数组是从1开始计数的，所以要加1
        }
    }
};

int main() {
    // 验证树状数组实现
    vector<int> nums = {1, 3, 5, 7, 9, 11}; // 原始数组
    FenwickTree fenwick(nums.size());
    fenwick.build(nums);

    // 计算前缀和并验证
    cout << "Prefix sum of [1, 3, 5] is: " << fenwick.query(3) << endl; // 应输出9 (1+3+5)
    cout << "Prefix sum of [1, 3, 5, 7] is: " << fenwick.query(4) << endl; // 应输出16 (1+3+5+7)

    // 单点更新并验证
    fenwick.update(2, 2); // 将index=2的位置的元素增加2，即3变为5（树状数组从1开始计数，实际更新的是nums[1]）
    cout << "After update, prefix sum of [1, 5, 5] is: " << fenwick.query(3) << endl; // 应输出11 (1+5+5)
    cout << "After update, prefix sum of [1, 5, 5, 7, 9, 11] is: " << fenwick.query(6) << endl; // 应输出38 (1+5+5+7+9+11)

    return 0;
}