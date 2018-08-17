//
// Created by schwarzeni on 2018/8/16.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_4_H
#define KAOYAN_DATA_STRUCTURE_T4_3_4_H

#include "binary_tree.h"
/**
 * 2018/8/16
 * p123
 * 二叉树自下而上，从右到左遍历
 */
namespace t_4_3_4 {
void LevelOrder(binaryTree::BiTree t) {
  auto *queue = new binaryTree::BiTree[100];
  auto q_head = 0;
  auto q_tail = 0;

  queue[q_tail++] = t;
  while (q_head != q_tail) {
    auto node = queue[q_head++];
    if (node != nullptr) {
      if (node->lchild != nullptr) {
        queue[q_tail++] = node->lchild;
      }
      if (node->rchild != nullptr) {
        queue[q_tail++] = node->rchild;
      }
    }
  }
  do {
    binaryTree::Visit(queue[--q_tail]);
  } while (q_tail > 0);
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  t_4_3_4::LevelOrder(t);
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_4_H
