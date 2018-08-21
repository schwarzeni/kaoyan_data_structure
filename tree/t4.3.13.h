//
// Created by schwarzeni on 2018/8/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_13_H
#define KAOYAN_DATA_STRUCTURE_T4_3_13_H

#include "binary_tree.h"
/**
 * 2018/8/21
 * p123
 * 求二叉树结点共同祖先
 * 思路
 *  使用递归算法求解
 */
namespace t_4_3_13 {
binaryTree::BiTree _find(binaryTree::BiTree b, binaryTree::ElemType v1, binaryTree::ElemType v2) {
  if (b == nullptr) return nullptr;
  if (b->data == v1 || b->data == v2) return b;

  binaryTree::BiTree bl = t_4_3_13::_find(b->lchild, v1, v2);
  binaryTree::BiTree br = t_4_3_13::_find(b->rchild, v1, v2);

  // 都不为空，则左右孩子都包括需要求的结点
  if (bl != nullptr && br != nullptr) return b;
  // 只有左孩子有
  if (bl != nullptr) return bl;
  // 只有右孩子有
  if (br != nullptr) return br;
  // 都没有
  return nullptr;
}

void Ancestor(binaryTree::BiTree b, binaryTree::ElemType v1, binaryTree::ElemType v2, binaryTree::BiTree &r) {
  r = t_4_3_13::_find(b, v1, v2);
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  binaryTree::BiTree node;
  t_4_3_13::Ancestor(t, 13, 50, node);
  std::cout << node->data << std::endl;
  t_4_3_13::Ancestor(t, 13, 1, node);
  std::cout << node->data << std::endl;
  t_4_3_13::Ancestor(t, 21, 4, node);
  std::cout << node->data << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_13_H
