//
// Created by schwarzeni on 2018/8/17.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_8_H
#define KAOYAN_DATA_STRUCTURE_T4_3_8_H

#include "binary_tree.h"
/**
 * 2018/8/17
 * p123
 * 求双分支结点个数
 * 思路：
 *  层序遍历，判断两个孩子是否都存在
 */
namespace t_4_3_8 {
int CountDoubleChildNode(binaryTree::BiTree t) {
  auto *queue = new binaryTree::BiTree[100];
  auto tail = -1,
      head = -1,
      count = 0;

  queue[++tail] = t;
  while (tail != head) {
    auto node = queue[++head];
    if (node->lchild != nullptr && node->rchild != nullptr) count++;
    if (node->lchild != nullptr) queue[++tail] = node->lchild;
    if (node->rchild != nullptr) queue[++tail] = node->rchild;
  }

  return count;
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  std::cout << t_4_3_8::CountDoubleChildNode(t) << std::endl;
  binaryTree::CreateACompleteTree(t);
  std::cout << t_4_3_8::CountDoubleChildNode(t) << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_8_H
