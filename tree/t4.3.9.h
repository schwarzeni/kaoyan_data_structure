//
// Created by schwarzeni on 2018/8/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_9_H
#define KAOYAN_DATA_STRUCTURE_T4_3_9_H

#include "binary_tree.h"
/**
 * 2018/8/18
 * p123
 * 将二叉树所有的左右子树进行交换
 * 思路：
 *  进行层序遍历，将遍历到的结点的左右孩子进行交换
 */
namespace t_4_3_9 {

void _switchChild(binaryTree::BiTree &T) {
  if (T != nullptr) {
    auto node = T->lchild;
    T->lchild = T->rchild;
    T->rchild = node;
  }
}

void Exchange(binaryTree::BiTree &T) {
  auto *queue = new binaryTree::BiTree[100];
  auto tail = -1,
       head = -1;

  queue[++tail] = T;
  while (head != tail) {
    auto node = queue[++head];
    if (node != nullptr) {
      _switchChild(node);
      if (node->lchild != nullptr) queue[++tail] = node->lchild;
      if (node->rchild != nullptr) queue[++tail] = node->rchild;
    }
  }
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  t_4_3_9::Exchange(t);
  binaryTree::LevelOrder(t);
}
}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_9_H
