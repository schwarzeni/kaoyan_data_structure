//
// Created by schwarzeni on 2018/8/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_11_H
#define KAOYAN_DATA_STRUCTURE_T4_3_11_H

#include "binary_tree.h"
/**
 * 2018/8/18
 * p123
 * 删除以val为值的根结点的树，并释放其空间
 * 思路：
 *  使用父亲结点来判断孩子结点，不能直接判断，否则根结点的空间无法释放
 */
namespace t_4_3_11 {
void _deleteChildNode(binaryTree::BiTree &T) {

  if (T->lchild != nullptr) _deleteChildNode(T->lchild);
  if (T->rchild != nullptr) _deleteChildNode(T->rchild);
  free(T);
  T = nullptr;
}

void DeleteByRootValue(binaryTree::BiTree &T, binaryTree::ElemType val) {

  if (T != nullptr && T->data == val) {
    t_4_3_11::_deleteChildNode(T);
    T = nullptr;
    return;
  }

  binaryTree::BiTree queue[100];
  auto tail = -1, head = -1;

  queue[++tail] = T;
  while (head != tail) {
    binaryTree::BiTree &node = queue[++head];
    if (node != nullptr) {

      if (node->lchild != nullptr) {
        if (node->lchild->data == val) {
          t_4_3_11::_deleteChildNode(node->lchild);
          node->lchild = nullptr;
        } else {
          queue[++tail] = node->lchild;
        }
      }

      if (node->rchild != nullptr) {
        if (node->rchild->data == val) {
          t_4_3_11::_deleteChildNode(node->rchild);
          node->rchild = nullptr;
        } else {
          queue[++tail] = node->rchild;
        }
      }
    }
  }
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  t_4_3_11::DeleteByRootValue(t, 4);
  binaryTree::LevelOrder(t);
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_11_H
