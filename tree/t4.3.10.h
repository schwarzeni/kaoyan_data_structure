//
// Created by schwarzeni on 2018/8/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_10_H
#define KAOYAN_DATA_STRUCTURE_T4_3_10_H

#include "binary_tree.h"
/**
 * 2018/8/18
 * 求先序遍历的第x个元素
 * 思路：
 *  注意，计算第几个时计数器需要共享，使用指针或者全局变量
 */
namespace t_4_3_10 {

binaryTree::ElemType notfind = -10000;

binaryTree::ElemType _preOrderGet(binaryTree::BiTree T, int idx, int *current) {
  binaryTree::ElemType data = notfind;
  if (*current == idx) return T->data;
  if (T->lchild != nullptr) {
    *current += 1;
    data = _preOrderGet(T->lchild, idx, current);
  }
  if (data != notfind) return data;
  if (T->rchild != nullptr) {
    *current += 1;
    data = _preOrderGet(T->rchild, idx, current);
  }
  if (data != notfind) return data;
  return data;
}

binaryTree::ElemType PreOrderGet(binaryTree::BiTree T, int idx) {
  if (T == nullptr) return notfind;
  // TODO: 注意，这里的count需要共享
  int count = 1;
  return t_4_3_10::_preOrderGet(T, idx, &count);
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  std::cout << t_4_3_10::PreOrderGet(t, 10) << std::endl;
  binaryTree::PreOrder(t);
}
}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_10_H
