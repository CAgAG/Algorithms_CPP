/*************************
 * @file   : 3_AVL_tree.cpp
 * @encode : UTF-8
 * @note   : None
 * @date   : 2024/6/2 10
 *************************/

#include "iostream"
#include "algorithm"
#include "assert.h"

using namespace std;

// 定义平衡二叉树的节点
struct AVLTreeNode {
    int data;
    int height;
    AVLTreeNode *left_child;
    AVLTreeNode *right_child;

    AVLTreeNode(int i_data) {
        data = i_data;
        height = 1;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class AVLTree {
private:
    AVLTreeNode *root;

    // 旋转操作
    AVLTreeNode *LeftRotate(AVLTreeNode *);

    AVLTreeNode *RightRotate(AVLTreeNode *);

    // 平衡因子
    int GetHeight(AVLTreeNode *);

    int GetBalanceFactor(AVLTreeNode *);

    // 辅助
    AVLTreeNode *InsertNode(AVLTreeNode *, AVLTreeNode *);

    AVLTreeNode *DeleteNode(AVLTreeNode *, AVLTreeNode *);

    bool del_flag;

public:
    void Insert(int);

    bool Delete(int);

    void InOrderPrint(AVLTreeNode *);

    AVLTreeNode *GetRoot();

    AVLTree() {
        root = nullptr;
    }

    AVLTreeNode *BalanceNode(AVLTreeNode *cur_node);
};

int AVLTree::GetHeight(AVLTreeNode *node) {
    if (node == nullptr) {
        return 0;
    } else if (node->left_child != nullptr && node->right_child == nullptr) {
        // 更新高度
        node->height = node->left_child->height + 1;
        return node->height;
    } else if (node->left_child == nullptr && node->right_child != nullptr) {
        // 更新高度
        node->height = node->right_child->height + 1;
        return node->height;
    } else if (node->left_child != nullptr && node->right_child != nullptr) {
        node->height = max(node->left_child->height, node->right_child->height) + 1;
        return node->height;
    } else {  // node->left_child == nullptr && node->right_child == nullptr
        node->height = 1;
        return node->height;
    }
}

int AVLTree::GetBalanceFactor(AVLTreeNode *node) {
    return GetHeight(node->left_child) - GetHeight(node->right_child);
}

// 左旋
// 返回旋转中心, 或者说是得到的新的根节点
AVLTreeNode *AVLTree::LeftRotate(AVLTreeNode *node) {
    // 记录
    AVLTreeNode *rotate_center = node->right_child;
    assert(rotate_center != nullptr);
    AVLTreeNode *rotate_target_pos_node = rotate_center->left_child;

    // 旋转
    rotate_center->left_child = node;
    node->right_child = rotate_target_pos_node;

    // 更新高度
    // 现有的右子树 可能比 原有的左子树高
    node->height = max(GetHeight(node->left_child), GetHeight(node->right_child)) + 1;
    // 更新旋转中心的高度
    rotate_center->height = max(GetHeight(rotate_center->left_child), GetHeight(rotate_center->right_child)) + 1;
    return rotate_center;
}

// 右旋
// 返回旋转中心, 或者说是得到的新的根节点
AVLTreeNode *AVLTree::RightRotate(AVLTreeNode *node) {
    // 记录
    AVLTreeNode *rotate_center = node->left_child;
    assert(rotate_center != nullptr);
    AVLTreeNode *rotate_target_pos_node = rotate_center->right_child;

    // 旋转
    rotate_center->right_child = node;
    node->left_child = rotate_target_pos_node;

    // 更新高度
    // 现有的右子树 可能比 原有的左子树高
    node->height = max(GetHeight(node->left_child), GetHeight(node->right_child)) + 1;
    // 更新旋转中心的高度
    rotate_center->height = max(GetHeight(rotate_center->left_child), GetHeight(rotate_center->right_child)) + 1;
    return rotate_center;
}

// TODO: 最重要的函数: 平衡节点
// 放在递归函数回溯的位置
AVLTreeNode *AVLTree::BalanceNode(AVLTreeNode *cur_node) {// L?型
    if (GetBalanceFactor(cur_node) == 2) {
        // LL 型
        if (GetBalanceFactor(cur_node->left_child) == 1) {
            cur_node = RightRotate(cur_node);
        } else if (GetBalanceFactor(cur_node->left_child) == -1) { // LR型
            cur_node->left_child = LeftRotate(cur_node->left_child);
            cur_node = RightRotate(cur_node);
        }
    } else if (GetBalanceFactor(cur_node) == -2) { // R?型
        // RR 型
        if (GetBalanceFactor(cur_node->right_child) == -1) {
            cur_node = LeftRotate(cur_node);
        } else if (GetBalanceFactor(cur_node->right_child) == 1) { // RL型
            cur_node->right_child = RightRotate(cur_node->right_child);
            cur_node = LeftRotate(cur_node);
        }
    }
    // 回溯, 不触发旋转也更新一下高度
    cur_node->height = max(GetHeight(cur_node->left_child), GetHeight(cur_node->right_child)) + 1;
    return cur_node;
}

AVLTreeNode *AVLTree::InsertNode(AVLTreeNode *cur_node, AVLTreeNode *new_node) {
    if (cur_node == nullptr) {
        return new_node;
    }

    if (new_node->data > cur_node->data) {
        cur_node->right_child = InsertNode(cur_node->right_child, new_node);
    }
    if (new_node->data < cur_node->data) {
        cur_node->left_child = InsertNode(cur_node->left_child, new_node);
    }

    // 平衡节点
    cur_node = BalanceNode(cur_node);
    return cur_node;
}

AVLTreeNode *AVLTree::DeleteNode(AVLTreeNode *cur_node, AVLTreeNode *new_node) {
    if (cur_node == nullptr) {
        return nullptr;
    }

    if (new_node->data == cur_node->data) {
        del_flag = true;
        if (cur_node->left_child == nullptr && cur_node->right_child == nullptr) {
            return nullptr;
        } else if (cur_node->left_child != nullptr && cur_node->right_child == nullptr) {
            AVLTreeNode *ret_node = cur_node->left_child;
            delete cur_node;
            return ret_node;
        } else if (cur_node->left_child == nullptr && cur_node->right_child != nullptr) {
            AVLTreeNode *ret_node = cur_node->right_child;
            delete cur_node;
            return ret_node;
        } else {
            AVLTreeNode *move_node = cur_node->left_child;
            AVLTreeNode *rl_node = cur_node->right_child;
            while (rl_node->left_child != nullptr) {
                rl_node = rl_node->left_child;
            }
            rl_node->left_child = move_node;

            AVLTreeNode *ret_node = cur_node->right_child;
            delete cur_node;
            return ret_node;
        }
    }

    if (new_node->data > cur_node->data) {
        cur_node->right_child = DeleteNode(cur_node->right_child, new_node);
    }
    if (new_node->data < cur_node->data) {
        cur_node->left_child = DeleteNode(cur_node->left_child, new_node);
    }
    // 平衡节点
    cur_node = BalanceNode(cur_node);
    return cur_node;
}


// public
void AVLTree::Insert(int data) {
    AVLTreeNode *new_node = new AVLTreeNode(data);

    // 根节点为空
    if (AVLTree::root == nullptr) {
        AVLTree::root = new_node;
        return;
    }

    AVLTree::root = InsertNode(AVLTree::root, new_node);
}

bool AVLTree::Delete(int data) {
    // 根节点为空
    if (AVLTree::root == nullptr) {
        return false;
    }
    del_flag = false;
    AVLTreeNode *del_node = new AVLTreeNode(data);

    if (root->data == data) {
        AVLTree::root = DeleteNode(AVLTree::root, del_node);
        BalanceNode(AVLTree::root);
    } else {
        AVLTree::root = DeleteNode(AVLTree::root, del_node);
    }
    return del_flag;
}


void AVLTree::InOrderPrint(AVLTreeNode *node) {
    if (node == nullptr) {
        return;
    }

    InOrderPrint(node->left_child);
    cout << node->data << " ";
    InOrderPrint(node->right_child);
}

AVLTreeNode *AVLTree::GetRoot() {
    return AVLTree::root;
}