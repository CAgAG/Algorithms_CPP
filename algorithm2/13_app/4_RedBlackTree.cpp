/*************************
 * @file   : 4_RedBlackTree.cpp
 * @encode : UTF-8
 * @note   : https://www.cnblogs.com/skywang12345/p/3624291.html (插入)和 https://www.bilibili.com/video/BV16m421u7Tb/ (删除)
 * @date   : 2024/6/2 17
 *************************/

// 定义节点颜色
#define NODE_RED 0
#define NODE_BLACK 1
// 双黑(仅在删除时使用)
#define NODE_DOUBLE_BLACK 2

#include "iostream"
#include "algorithm"
#include "assert.h"

using namespace std;


struct RBTreeNode {
    int data;
    // 红: 0, 黑: 1, 双黑(仅在删除时使用): 2
    int color;

    RBTreeNode *left_child;
    RBTreeNode *right_child;
    RBTreeNode *parent;

    RBTreeNode(int i_data) {
        data = i_data;
        color = NODE_RED;
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr;
    }
};

struct RBTree {
private:
    RBTreeNode *root;

    void FlipColor(RBTreeNode *);

    // 旋转操作
    RBTreeNode *LeftRotate(RBTreeNode *);

    RBTreeNode *RightRotate(RBTreeNode *);

    // 辅助
    void InsertNodeBySearchTree(RBTreeNode *);

    void FixInsert(RBTreeNode *);

    RBTreeNode *FindDelNode(RBTreeNode *);

    void FixDelete(RBTreeNode *);


public:
    void Insert(int);

    bool Delete(int);

    void InOrderPrint(RBTreeNode *);

    RBTreeNode *GetRoot();

    RBTree() {
        root = nullptr;
    }
};

RBTreeNode *RBTree::GetRoot() {
    return root;
}

void RBTree::FlipColor(RBTreeNode *data) {
    if (data == nullptr) {
        return;
    }

    if (data->color == NODE_RED) {
        data->color = NODE_BLACK;
    } else {
        data->color = NODE_RED;
    }
}

// ============================================
// 右旋
RBTreeNode *RBTree::RightRotate(RBTreeNode *node) {
    // 将其转换为 AVL树的左旋操作
    RBTreeNode *rotate_node = node;
    RBTreeNode *rotate_center_node = node->left_child;

    // 移动, 左右旋的差别只在 移动阶段
    rotate_node->left_child = rotate_center_node->right_child;
    if (rotate_center_node->right_child != nullptr) {
        rotate_center_node->right_child->parent = rotate_node;
    }
    rotate_center_node->right_child = rotate_node;

    // 更新父节点
    rotate_center_node->parent = rotate_node->parent;
    if (rotate_node->parent == nullptr) {  // 为空, 说明rotate_node是根节点, 就设置成根节点
        root = rotate_center_node;
    } else {
        // 更新 rotate_node->parent 的孩子指向
        if (rotate_node->parent->left_child == rotate_node) {  // 确定是左节点还是右节点
            rotate_node->parent->left_child = rotate_center_node;
        } else {
            rotate_node->parent->right_child = rotate_center_node;
        }
    }
    rotate_node->parent = rotate_center_node;
    return rotate_center_node;
}


// 左旋
RBTreeNode *RBTree::LeftRotate(RBTreeNode *node) {
    // 将其转换为 AVL树的左旋操作
    RBTreeNode *rotate_node = node;
    RBTreeNode *rotate_center_node = node->right_child;

    // 移动
    rotate_node->right_child = rotate_center_node->left_child;
    if (rotate_center_node->left_child != nullptr) {
        rotate_center_node->left_child->parent = rotate_node;
    }
    rotate_center_node->left_child = rotate_node;

    // 更新父节点
    rotate_center_node->parent = rotate_node->parent;
    if (rotate_node->parent == nullptr) {  // 为空, 说明rotate_node是根节点, 就设置成根节点
        root = rotate_center_node;
    } else {
        // 更新 rotate_node->parent 的孩子指向
        if (rotate_node->parent->left_child == rotate_node) {  // 确定是左节点还是右节点
            rotate_node->parent->left_child = rotate_center_node;
        } else {
            rotate_node->parent->right_child = rotate_center_node;
        }
    }
    rotate_node->parent = rotate_center_node;
    return rotate_center_node;
}


// 插入 ============================================
// 插入只有 违反 不能出现连续红色节点的规则
// 先作为二叉搜索树插入节点, 注意parent节点的更新
void RBTree::InsertNodeBySearchTree(RBTreeNode *new_node) {
    RBTreeNode *cur_node = root;
    RBTreeNode *InsertParent = cur_node;
    while (cur_node != nullptr) {
        InsertParent = cur_node;
        if (new_node->data > cur_node->data) {
            cur_node = cur_node->right_child;
        } else {
            cur_node = cur_node->left_child;
        }
    }
    // 更新父节点
    new_node->parent = InsertParent;
    if (InsertParent != nullptr) {
        if (new_node->data > InsertParent->data) {
            InsertParent->right_child = new_node;
        } else {
            InsertParent->left_child = new_node;
        }
    } else {
        root = new_node;
    }
    // 默认 红色节点
    new_node->color = NODE_RED;
}

bool IsRed(RBTreeNode *node) {
    if (node != nullptr && node->color == NODE_RED) {
        return true;
    }
    return false;
}

void RBTree::FixInsert(RBTreeNode *cur_node) {
    RBTreeNode *parent, *grand_parent, *uncle;

    // 若父节点存在，并且父节点的颜色是红色: (连续两个红色节点)
    while (IsRed(cur_node->parent)) {
        parent = cur_node->parent;
        grand_parent = parent->parent;

        // uncle node 在 爷节点的哪个孩子上
        if (grand_parent->left_child == parent) {  // 父节点在左孩子上
            uncle = grand_parent->right_child; // 右孩子上
            if (IsRed(uncle)) { // uncle node 是红色
                uncle->color = NODE_BLACK;
                parent->color = NODE_BLACK;
                grand_parent->color = NODE_RED;  // 注意: 变成红色, 因为要变成插入节点
                cur_node = grand_parent;  // 变成插入节点
                continue;
            }

            // uncle node 是黑色
            // 判断旋转类型: LL, LR型, 对旋转中心和旋转点变色
            // LR 型
            if (parent->right_child == cur_node) {  // 当前节点在 父节点的左边
                LeftRotate(grand_parent->left_child);  // 其实就是 parent, 转成 LL型
                RightRotate(grand_parent);  // 就是把 grand_parent旋转下去
                FlipColor(cur_node);
                FlipColor(grand_parent);
            } else {  // LL型
                RightRotate(grand_parent);
                FlipColor(parent);
                FlipColor(grand_parent);
            }

        } else { // 父节点在右孩子上
            uncle = grand_parent->left_child;
            if (IsRed(uncle)) { // uncle node 是红色
                uncle->color = NODE_BLACK;
                parent->color = NODE_BLACK;
                grand_parent->color = NODE_RED;  // 注意: 变成红色, 因为要变成插入节点
                cur_node = grand_parent;  // 变成插入节点
                continue;
            }

            // uncle node 是黑色
            // 判断旋转类型: RR, RL型, 对旋转中心和旋转点变色
            // RL 型
            if (parent->left_child == cur_node) {  // 当前节点在 父节点的左边
                RightRotate(grand_parent->right_child);  // 其实就是 parent, 转成 RR型
                LeftRotate(grand_parent);  // 就是把 grand_parent旋转下去
                FlipColor(cur_node);
                FlipColor(grand_parent);
            } else {  // RR型
                LeftRotate(grand_parent);
                FlipColor(parent);
                FlipColor(grand_parent);
            }

        }

    }
    root->color = NODE_BLACK;
}

void RBTree::Insert(int data) {
    // 插入的节点默认为红色
    RBTreeNode *new_node = new RBTreeNode(data);
    new_node->color = NODE_RED;
    if (GetRoot() == nullptr) {
        new_node->color = NODE_BLACK;
        RBTree::root = new_node;
        return;
    }
    InsertNodeBySearchTree(new_node);
    FixInsert(new_node);
}

// 删除 ============================================
// 找到符合红黑树删除条件的节点; 返回【非左右孩子都在】的 要删除节点
RBTreeNode *RBTree::FindDelNode(RBTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    // 找到要删除的节点
    RBTreeNode *del_node = root;  // 右可能就是 根节点
    while (del_node != nullptr && node->data != del_node->data) {
        if (node->data > del_node->data) {
            del_node = del_node->right_child;
        } else {
            del_node = del_node->left_child;
        }
    }
    if (del_node == nullptr) {
        return nullptr;
    }

    // 如果遇到 删除节点 存在左右子树的情况; 则需要继续转换, 转成其中一个孩子是 null 的情况
    if (del_node->left_child != nullptr && del_node->right_child != nullptr) {
        // 通过直接 后继 来删除: 右子树中最小的
        RBTreeNode *will_del_node = del_node->right_child;
        while (will_del_node->left_child != nullptr) {  // 注意: 此时输出的节点 左子树为空
            will_del_node = will_del_node->left_child;
        }

        // 更新节点信息 =============================
        del_node->data = will_del_node->data;
        del_node->color = will_del_node->color;
        // 更新节点信息 =============================

        return will_del_node;  // 转换 del_node
    }
    return del_node;
}


void RBTree::FixDelete(RBTreeNode *node) {
    RBTreeNode *del_node = FindDelNode(node);
    if (del_node == nullptr) {
        return;
    }

    if (del_node == root) {
        if (root->left_child != nullptr && root->right_child == nullptr) {
            root = root->left_child;
        } else if (root->left_child == nullptr && root->right_child != nullptr) {
            root = root->right_child;
        } else {
            root = nullptr;
        }
        return;
    }

    RBTreeNode *del_node_parent = del_node->parent;
    // 删除节点是否在其 父亲节点的左边
    bool del_left_pos_flag = del_node_parent->left_child == del_node;
    // 只有左孩子或者是只有右孩子 ========================
    if (del_node->left_child != nullptr && del_node->right_child == nullptr) {
        if (del_left_pos_flag) {
            del_node_parent->left_child = del_node->left_child;
        } else {
            del_node_parent->right_child = del_node->left_child;
        }
        delete del_node;
        return;
    } else if (del_node->left_child == nullptr && del_node->right_child != nullptr) {
        if (del_left_pos_flag) {
            del_node_parent->left_child = del_node->right_child;
        } else {
            del_node_parent->right_child = del_node->right_child;
        }
        delete del_node;
        return;
    }

    // 没有孩子 ======================================
    // del_node->left_child == nullptr && del_node->right_child == nullptr
    if (IsRed(del_node)) {  // 删除节点是红色
        if (del_left_pos_flag) {
            del_node_parent->left_child = nullptr;
        } else {
            del_node_parent->right_child = nullptr;
        }
        delete del_node;
        return;
    }

    // 双黑 节点处理
    // 删除节点是 红色或者 “双黑”
    RBTreeNode *cur_del_node = del_node;  // 处理的节点, 也可能是双黑节点
    cur_del_node->color = NODE_DOUBLE_BLACK;
    while (cur_del_node != root) {
        // 消除 双黑节点
        if (cur_del_node->color != NODE_DOUBLE_BLACK) {
            break;
        }

        // 兄弟节点
        RBTreeNode *bro_node;
        // 删除节点是否在其 父亲节点的左边
        del_node_parent = cur_del_node->parent;
        del_left_pos_flag = del_node_parent->left_child == cur_del_node;

        if (del_left_pos_flag) {
            bro_node = del_node_parent->right_child;
        } else {
            bro_node = del_node_parent->left_child;
        }

        // 保持双黑
        if (IsRed(bro_node)) {  // 兄弟节点是 红色
            // 兄 父 变色
            FlipColor(bro_node);
            FlipColor(del_node_parent);
            // 父节点 向 删除节点旋转
            if (del_left_pos_flag) {
                LeftRotate(del_node_parent);
            } else {
                RightRotate(del_node_parent);
            }
        } else {  // 兄弟节点是 黑色 或者双黑; 双黑 转移
            // 兄弟节点的孩子都是黑色节点
            if (!IsRed(bro_node->left_child) && !IsRed(bro_node->right_child)) {
                // 兄弟变红
                bro_node->color = NODE_RED;
                // 双黑上移 (转移)
                cur_del_node->color = NODE_BLACK;
                // 如果遇到 红色 或者 根节点直接变 单黑即可; 双黑消除, 结束
                cur_del_node = cur_del_node->parent;
                if (IsRed(cur_del_node) || cur_del_node == root) {
                    cur_del_node->color = NODE_BLACK;
                } else {
                    cur_del_node->color = NODE_DOUBLE_BLACK;
                }
            } else {  // 兄弟节点的孩子 至少有一个是 红色; 双黑 变单黑
                RBTreeNode *p = bro_node->parent;
                RBTreeNode *s = bro_node;
                // L? 型; 【第二个字母实际是 红色节点的位置】
                if (!del_left_pos_flag) {  // 兄弟节点在 其父节点的左边
                    RBTreeNode *r = bro_node->left_child;
                    if (IsRed(r)) { // 只要左孩子是红色, 就默认是 LL型
                        // 变色
                        r->color = s->color;
                        s->color = p->color;
                        p->color = NODE_BLACK;
                        // 右旋
                        RightRotate(p);

                    } else {  // LR型
                        r = bro_node->right_child;  // r 改成红色节点的位置
                        // 变色, 与上面的有所不同, 不需要对s变色
                        r->color = p->color;
                        p->color = NODE_BLACK;
                        // 旋转
                        LeftRotate(p->left_child);
                        RightRotate(p);
                    }

                } else {  // 兄弟节点在 其父节点的右边
                    RBTreeNode *r = bro_node->right_child;
                    if (IsRed(r)) {  // RR 型
                        // 变色
                        r->color = s->color;
                        s->color = p->color;
                        p->color = NODE_BLACK;
                        // 左旋
                        LeftRotate(p);
                        cur_del_node->color = NODE_BLACK;
                    } else {  // RL 型
                        r = bro_node->left_child;  // r 改成红色节点的位置
                        // 变色, 与上面的有所不同, 不需要对s变色
                        r->color = p->color;
                        p->color = NODE_BLACK;
                        // 旋转
                        RightRotate(p->right_child);
                        LeftRotate(p);
                    }
                }
                cur_del_node->color = NODE_BLACK;
            }
        }


    }

    if (del_node->parent->left_child == del_node) {
        del_node->parent->left_child = nullptr;
    } else {
        del_node->parent->right_child = nullptr;
    }
    delete del_node;
    root->color = NODE_BLACK;
    return;
}


bool RBTree::Delete(int data) {
    if (GetRoot() == nullptr) {
        return false;
    }
    RBTreeNode *del_node = new RBTreeNode(data);
    // RBTreeNode *del_node_p = DeleteNodeBySearchTree(del_node);
    // if (del_node_p == nullptr) {
    //     return false;
    // }
    FixDelete(del_node);
    return true;
}

// 打印调试
void RBTree::InOrderPrint(RBTreeNode *node) {
    if (node == nullptr) {
        return;
    }

    InOrderPrint(node->left_child);
    cout << node->data << " ";
    InOrderPrint(node->right_child);
}