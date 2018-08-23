//
// Created by schwarzeni on 2018/8/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_THREADED_BINARY_TREE_H
#define KAOYAN_DATA_STRUCTURE_THREADED_BINARY_TREE_H

/**
 * 2018/8/23
 */
// TODO: 结构记得加上tag判断是线索还是孩子结点
#include "binary_tree.h"
namespace threadedBinaryTree {
void _inOrder(binaryTree::BiTree &t, binaryTree::BiTree &prev) {
  if (t == nullptr) return;
  _inOrder(t->lchild, prev);

  if (prev != nullptr && prev->rchild == nullptr) {
    prev->rchild = t;
  }
  if (prev != nullptr && t->lchild == nullptr) {
    t->lchild = prev;
  }
  prev = t;

  _inOrder(t->rchild, prev);
}
void InOrderize(binaryTree::BiTree &t) {
  binaryTree::BiTree prev = nullptr;
  threadedBinaryTree::_inOrder(t, prev);
}

void _testInOrderize(binaryTree::BiTree &t) {
  while (t->lchild != nullptr) {
    t = t->lchild;
  }
  while (true) {
    if (t == nullptr) break;
    std::cout << t->data << " ";
    t = t->rchild;
  };
  std::cout << std::endl;
}
}
#endif //KAOYAN_DATA_STRUCTURE_THREADED_BINARY_TREE_H
