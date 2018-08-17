//
// Created by schwarzeni on 2018/8/16.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_5_H
#define KAOYAN_DATA_STRUCTURE_T4_3_5_H

#include "binary_tree.h"
/**
 * 2018/8/16
 * p123
 * 非递归求二叉树的高度
 * 使用非递归层序遍历算法，其中加上高度的计算和判断
 */
namespace t_4_3_5 {
bool NotLeaf(binaryTree::BiTree node) {
  return node->lchild != nullptr || node->rchild != nullptr;
}

int Height(binaryTree::BiTree t) {
  auto maxdepth = 0;
  auto depth = 0;
  auto *stack = new binaryTree::BiTree[100];
  auto stackDepth = -1;
  auto node = t;

//  if (node == nullptr) return 0;

  while (stackDepth >= 0 || node != nullptr) {
    if (node != nullptr) {
      stack[++stackDepth] = node;
      if (NotLeaf(node)) {
        depth++;
        if (depth > maxdepth) {
          maxdepth = depth;
        }
      }
      node = node->lchild;
    } else {
      node = stack[stackDepth--];
      if (NotLeaf(node)) {
        depth--;
      }
      node = node->rchild;
    }
  }
  return maxdepth + 1;
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  std::cout << t_4_3_5::Height(t) << std::endl;
}

}
#endif //KAOYAN_DATA_STRUCTURE_T4_3_5_H
