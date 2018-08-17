//
// Created by schwarzeni on 2018/7/31.
//

#ifndef KAOYAN_DATA_STRUCTURE_TREE_H
#define KAOYAN_DATA_STRUCTURE_TREE_H

#include <iostream>
namespace binaryTree {
typedef int ElemType;

/**
 * 2018/7/31
 * 定义二叉树的结构
 */
typedef struct BiTNode {
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * 2018/7/31
 * 创建一个新结点
 */
void CreateNewNode(BiTNode *&node, ElemType data, BiTNode *left, BiTNode *right) {
  node = new BiTNode{};
  node->data = data;
  node->lchild = left;
  node->rchild = right;
}

/**
 * 2018/7/31
 * 生成一个定义好的二叉树
 *
 *         5
 *       /    \
 *     4       3
 *    / \     / \
 *   6   1   2   32
 *  / \           \
 * 13  45         50
 * /                \
 *21                41
 */
void CreateANewTree(BiTree &t) {
  BiTNode *node1 = nullptr;
  BiTNode *node2 = nullptr;
  BiTNode *node3 = nullptr;

  CreateNewNode(node2, 21, nullptr, nullptr);

  CreateNewNode(node1, 13, node2, nullptr);
  CreateNewNode(node2, 45, nullptr, nullptr);
  CreateNewNode(node3, 6, node1, node2);

  CreateNewNode(node1, 1, nullptr, nullptr);
  CreateNewNode(node2, 4, node3, node1);
  CreateNewNode(node1, 5, node2, nullptr);
  t = node1;

  CreateNewNode(node1, 2, nullptr, nullptr);
  CreateNewNode(node2, 32, nullptr, nullptr);
  CreateNewNode(node3, 3, node1, node2);
  t->rchild = node3;

  CreateNewNode(node1, 41, nullptr, nullptr);
  CreateNewNode(node3, 50, nullptr, node1);
  node2->rchild = node3;
}

/**
 * 2018/8/17
 * 创建一棵完全二叉树
 */
void CreateACompleteTree(BiTree &t) {
  BiTNode *node1 = nullptr;
  BiTNode *node2 = nullptr;
  BiTNode *node3 = nullptr;

  CreateNewNode(node3, 6, node1, node2);

  CreateNewNode(node1, 1, nullptr, nullptr);
  CreateNewNode(node2, 4, node3, node1);
  CreateNewNode(node1, 5, node2, nullptr);
  t = node1;

  CreateNewNode(node1, 2, nullptr, nullptr);
  CreateNewNode(node2, 32, nullptr, nullptr);
  CreateNewNode(node3, 3, node1, node2);
  t->rchild = node3;
}

/**
 *  2018/8/4
 *  访问一个节点
 */
void Visit(BiTNode *node) {
  std::cout << node->data << " ";
}

/**
 * 2018/8/4
 * 先序遍历
 */
void PreOrder(BiTree T) {
  if (T != nullptr) {
    Visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}
/**
 * 2018/8/4
 * 先序遍历，非递归
 */
void PreOrder2(BiTree T) {
  auto node = T;
  auto *stack = new BiTree[100];
  int itemcount = -1;

  while (itemcount >= 0 || node != nullptr) {
    if (node != nullptr) {
      Visit(node);                    // 先访问当前结点
      stack[++itemcount] = node;      // 根指针进栈
      node = node->lchild;            // 访问子树
    } else {
      node = stack[itemcount--];      // 根指针退栈
      node = node->rchild;            // 访问右子树
    }
  }

}

/**
 * 2018/8/4
 * 中序遍历
 */
void InOrder(BiTree T) {
  if (T != nullptr) {
    InOrder(T->lchild);
    Visit(T);
    InOrder(T->rchild);
  }
}

/**
 * 2018/8/4
 * 中序遍历，非递归
 */
void InOrder2(BiTree T) {
  auto node = T;
  auto *stack = new BiTree[100];
  int itemcount = -1;

  while (itemcount >= 0 || node != nullptr) {
    if (node != nullptr) {
      stack[++itemcount] = node;
      node = node->lchild;
    } else {
      node = stack[itemcount--];
      Visit(node);
      node = node->rchild;
    }
  }
}

/**
 * 2018/8/4
 * 后序遍历
 */
void PostOrder(BiTree T) {
  if (T != nullptr) {
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    Visit(T);
  }
}

/**
 * 2018/8/4
 * 后序遍历，非递归
 */
void PostOrder2(BiTree T) {
  auto node = T;
  BiTree prev = nullptr; // 前一个访问的结点
  auto *stack = new BiTree[100];
  int itemcount = -1;

  stack[++itemcount] = node;

  while (itemcount >= 0) {

    node = stack[itemcount];

    // 不存在左孩子右孩子
    // 或 左孩子和右孩子已经被访问过了
    if ((node->lchild == nullptr && node->rchild == nullptr
        || (prev != nullptr && (prev == node->lchild || prev == node->rchild)))) {
      Visit(node);
      itemcount--;
      prev = node;
    } else {
      // 注意顺序，右孩子左孩子依次入栈
      // 这样弹出栈的时候先为左孩子再为右孩子
      if (node->rchild != nullptr) {
        stack[++itemcount] = node->rchild;
      }
      if (node->lchild != nullptr) {
        stack[++itemcount] = node->lchild;
      }
    }
  }
}

/**
 * 2018/8/4
 * 层序遍历
 */
void LevelOrder(BiTree T) {
  auto *queue = new BiTree[100];
  int head = 0;
  int tail = 0;

  queue[tail++] = T;

  while (head < tail) {
    auto node = queue[head++];
    Visit(node);
    if (node->lchild != nullptr)
      queue[tail++] = node->lchild;
    if (node->rchild != nullptr)
      queue[tail++] = node->rchild;
  }
}

/**
 * 2018/8/12
 * 求树的深度
 * 求二叉树的深度
 */
int Depth(BiTree T) {
  if (T == nullptr) return 0;

  int leftDepth = Depth(T->lchild);
  int rightDepth = Depth(T->rchild);
  if (leftDepth > rightDepth)
    return ++leftDepth;
  else
    return ++rightDepth;
}

}

#endif //KAOYAN_DATA_STRUCTURE_TREE_H
