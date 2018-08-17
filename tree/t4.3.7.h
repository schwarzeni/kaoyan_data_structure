//
// Created by schwarzeni on 2018/8/17.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_7_H
#define KAOYAN_DATA_STRUCTURE_T4_3_7_H

#include "binary_tree.h"
/**
 * 2018/8/17
 * p123
 * 验证是否为完全二叉树
 * 思路：
 *  使用层序遍历的队列，但是空结点孩子也需入队列
 *  遇到空结点退出循环，并查看队列中是否有非空孩子
 */
namespace t_4_3_7 {
bool CheckComplete(binaryTree::BiTree t) {
  auto *queue = new binaryTree::BiTree[100]{};
  int tail = -1;
  int head = -1;

  queue[++tail] = t;
  binaryTree::BiTree node;
  while (true) {
    node = queue[++head];
    if (node == nullptr) break;
    queue[++tail] = node->lchild;
    queue[++tail] = node->rchild;
  }
  // 查看余下的队列中的数字是否包含非空结点
  while (head != tail) {
    if (queue[++head] != nullptr) return false;
  }
  return true;
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  std::cout << t_4_3_7::CheckComplete(t) << std::endl;
  binaryTree::CreateACompleteTree(t);
  std::cout << t_4_3_7::CheckComplete(t) << std::endl;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_7_H
