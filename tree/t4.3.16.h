//
// Created by schwarzeni on 2018/8/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_16_H
#define KAOYAN_DATA_STRUCTURE_T4_3_16_H

#include "binary_tree.h"
/**
 * 2018/8/23
 * p124
 * 将二叉树孩子结点从左到右串成一个链表
 * 思路：
 *  使用先序递归即可
 */
namespace t_4_3_16 {

void _getNext(binaryTree::BiTree &t, binaryTree::BiTree &head, binaryTree::BiTree &prevChild) {
  if (t == nullptr) return;
  if (t->lchild == nullptr && t->rchild == nullptr) {
    if (prevChild != nullptr) {
      prevChild->rchild = t;
    } else {
      head = t;
    }
    prevChild = t;
    return;
  }
  _getNext(t->lchild, head, prevChild);
  _getNext(t->rchild, head, prevChild);
}

void ChildNodeChain(binaryTree::BiTree &T, binaryTree::BiTree &head) {
  binaryTree::BiTree prev = nullptr;
  t_4_3_16::_getNext(T, head, prev);
}

void Test() {
  binaryTree::BiTree t, head = nullptr;
  binaryTree::CreateANewTree(t);
  t_4_3_16::ChildNodeChain(t, head);
  while (head != nullptr) {
    std::cout << head->data << " ";
    head = head->rchild;
  }
  std::cout << std::endl;
}

}
#endif //KAOYAN_DATA_STRUCTURE_T4_3_16_H
