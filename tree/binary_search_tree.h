//
// Created by schwarzeni on 2018/8/16.
//

#ifndef KAOYAN_DATA_STRUCTURE_BINARY_SEARCH_TREE_H
#define KAOYAN_DATA_STRUCTURE_BINARY_SEARCH_TREE_H

#include "binary_tree.h"
namespace binarySearchTree {

/**
 * 2018/8/16
 * 对二叉搜索树进行出入操作
 */
bool Insert(binaryTree::BiTree &T, binaryTree::ElemType k) {
  if (T == nullptr) {
    T = new binaryTree::BiTNode{};
    T->data = k;
    T->lchild = T->rchild = nullptr;
    return true;
  } else if (T->data == k) {
    return false;
  } else if (k < T->data) {
    return Insert(T->lchild, k);
  } else {
    return Insert(T->rchild, k);
  }
}

/**
 * 2018/8/16
 * 创建一个新的二叉搜索树
 */
void CreateBST(binaryTree::BiTree &T) {
  Insert(T, 6);
  Insert(T, 2);
  Insert(T, 8);
  Insert(T, 1);
  Insert(T, 4);
  Insert(T, 3);
}
}

#endif //KAOYAN_DATA_STRUCTURE_BINARY_SEARCH_TREE_H
