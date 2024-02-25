/*************************
 * @file   : ST.cpp
 * @encode : UTF-8
 * @note   : 线段树（Segment Tree）是一种二叉树结构，用于存储区间或线段的信息，它允许查询和修改这些区间的高效操作。
 *           线段树常用于解决涉及区间查询和更新的问题，如区间求和、区间最大值等。
 * @date   : 2024/2/25 15
 *************************/

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class SegmentTree {
private:
    vector<int> tree;
    vector<int> nums;
    int n;

    /* 注意: int start, int end 指的是 nums的区间, 不是tree的 */
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node + 1, start, mid);
            buildTree(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // 单个值更新  ==> TODO: 多个值更新?
    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            nums[idx] = val;
            tree[node] = val;
            return;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateTree(2 * node + 1, start, mid, idx, val);
            } else {
                updateTree(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int sumLeft = queryTree(2 * node + 1, start, mid, l, r);
        int sumRight = queryTree(2 * node + 2, mid + 1, end, l, r);
        return sumLeft + sumRight;
    }

    int queryTree2(int node, int start, int end, int l, int r) {
        if (l == start && end == r) {
            // 查询范围完全包含当前节点范围
            return tree[node];
        }
        int mid = (start + end) / 2;
        if (r <= mid) {
            // 查询范围完全在左子树内
            return queryTree2(2 * node + 1, start, mid, l, r);
        } else if (l > mid) {
            // 查询范围完全在右子树内
            return queryTree2(2 * node + 2, mid + 1, end, l, r);
        } else {
            // 查询范围跨中点，既在左子树又在右子树内
            return queryTree2(2 * node + 1, start, mid, l, mid) +
                   queryTree2(2 * node + 2, mid + 1, end, mid + 1, r);
        }
    }

public:
    SegmentTree(vector<int> &nums) {
        this->nums = nums;
        n = nums.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }

    int query(int left, int right) {
        return queryTree2(0, 0, n - 1, left, right);
    }

    void print_inner_nums() {
        print_vector(this->nums);
    }

    void print_inner_tree() {
        print_vector(this->tree);
    }
};


int main() {
    // 验证线段树实现
    vector<int> nums = {1, 3, 5, 7, 9, 11}; // 原始数组
    SegmentTree segTree(nums); // 构建线段树

    // 查询区间和并验证
    segTree.print_inner_nums();
    segTree.print_inner_tree();
    cout << "Sum of [1, 3, 5] is: " << segTree.query(0, 2) << endl; // 应输出9 (1+3+5)
    cout << "Sum of [1, 3, 5, 7] is: " << segTree.query(0, 3) << endl; // 应输出16 (1+3+5+7)

    // 单点更新并验证
    segTree.update(2, 6); // 将index=2的位置的元素更新为6（实际更新的是nums[2]）
    segTree.print_inner_nums();
    segTree.print_inner_tree();
    cout << "After update, sum of [1, 3, 6] is: " << segTree.query(0, 2) << endl; // 应输出10 (1+3+6)
    cout << "After update, sum of [1, 3, 6, 7, 9, 11] is: " << segTree.query(0, 5) << endl; // 应输出37 (1+3+6+7+9+11)

    return 0;
}
