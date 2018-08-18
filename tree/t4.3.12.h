//
// Created by schwarzeni on 2018/8/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_12_H
#define KAOYAN_DATA_STRUCTURE_T4_3_12_H

#include "binary_tree.h"
/**
 * 2018/8/18
 * p123
 * 打印值为val的结点的所有祖先结点
 * 思路：
 *  如果找到返回true，递归，判读递归返回的是否有true，存在则其为祖先结点
 */
namespace t_4_3_12 {

void _printNode(binaryTree::BiTree t) {
  std::cout << t->data << " ";
}

bool _hasChildByVal(binaryTree::BiTree t, binaryTree::ElemType val) {
  if (t == nullptr) return false;
  if (t->data == val) {
    _printNode(t);
    return true;
  }

  bool lt = false;
  bool rt = false;
  if (t->lchild != nullptr)
    lt = t_4_3_12::_hasChildByVal(t->lchild, val);
  if (t->rchild != nullptr)
    rt = t_4_3_12::_hasChildByVal(t->rchild, val);

  // 存在true则其为祖先结点
  if (lt || rt) {
    t_4_3_12::_printNode(t);
    return true;
  } else {
    return false;
  }
}

void PrintAncestor(binaryTree::BiTree t, binaryTree::ElemType val) {
  t_4_3_12::_hasChildByVal(t, val);
  std::cout << std::endl;
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  t_4_3_12::PrintAncestor(t, 50);
  t_4_3_12::PrintAncestor(t, 45);
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_12_H
