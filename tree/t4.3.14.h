//
// Created by schwarzeni on 2018/8/21.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_14_H
#define KAOYAN_DATA_STRUCTURE_T4_3_14_H

#include "binary_tree.h"
/**
 * 2018/8/12
 * p123
 * 求二叉树宽度
 * 思路
 *  层序遍历求解，空指针也入队列
 */
namespace t_4_3_14 {
int Width(binaryTree::BiTree t) {
  int divide = 1;
  int total = 0;
  binaryTree::BiTree queue[1000];
  int tail = -1;
  int head = -1;
  int max = 0;
  int count = 0;
  queue[++tail] = t;

  while (true) {
    auto node = queue[++head];
    total++;
    if (node != nullptr) {
      count++;
      queue[++tail] = node->lchild;
      queue[++tail] = node->rchild;
    } else {
      queue[++tail] = nullptr;
      queue[++tail] = nullptr;
    }

    // 计算一层是否结束
    if (total % divide == 0) {
      // 如果当前层都为空指针，则退出
      if (count == 0) break;
      max = max > count ? max : count;
      count = 0;
      total = 0;
      divide *= 2;
    }
  }

  return max;
}

void Test() {
  binaryTree::BiTree t;
  binaryTree::CreateANewTree(t);
  std::cout << t_4_3_14::Width(t) << std::endl;
  std::cout << t_4_3_14::Width(t->lchild) << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_14_H
