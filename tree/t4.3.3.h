//
// Created by schwarzeni on 2018/8/16.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_3_H
#define KAOYAN_DATA_STRUCTURE_T4_3_3_H

#include "binary_tree.h"
/**
 * 2018/8/16
 * p123
 * 后序非递归遍历二叉树
 */
namespace t_4_3_3 {
void PostOrder(binaryTree::BiTree t) {
  auto *stack = new binaryTree::BiTree[100];
  int stackDepth = -1;
  binaryTree::BiTree prev = nullptr;

  stack[++stackDepth] = t;
  while (stackDepth >= 0) {
    auto node = stack[stackDepth];

    if ((node->lchild == nullptr && node->rchild == nullptr)
        || (prev != nullptr && (prev == node->lchild || prev == node->rchild))) {
      binaryTree::Visit(node);
      prev = node;
      stackDepth--;
    } else {
      if (node->rchild != nullptr) {
        stack[++stackDepth] = node->rchild;
      }
      if (node->lchild != nullptr) {
        stack[++stackDepth] = node->lchild;
      }
    }
  }
}

void Test() {
  binaryTree::BiTree b;
  binaryTree::CreateANewTree(b);
  t_4_3_3::PostOrder(b);
}
}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_3_H
