//
// Created by schwarzeni on 2018/8/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_19_H
#define KAOYAN_DATA_STRUCTURE_T4_3_19_H

#include "binary_tree.h"
#include "binary_search_tree.h"
/**
 * 2018/8/23
 * 求树的带权路径程度
 * p124
 * 思路
 *  先序遍历稍微修改即可
 */
namespace t_4_3_19 {

/*****  解法1  指针版*/
void _getNextNode(binaryTree::BiTree t, int count, int *total) {
  if (t->lchild == nullptr && t->rchild == nullptr) {
    *total += count * t->data;
  }

  count++;
  if (t->lchild != nullptr) _getNextNode(t->lchild, count, total);
  if (t->rchild != nullptr) _getNextNode(t->rchild, count, total);
}

int GetWPL(binaryTree::BiTree t) {
  int total = 0;
  _getNextNode(t, 0, &total);
  return t == nullptr ? 0 : total;
}
/*  解法1  ****/

/****  解法2 返回值版 */
int _getNextNode2(binaryTree::BiTree t, int count, int total) {
  if (t->lchild == nullptr && t->rchild == nullptr) {
    return total += count * t->data;
  }

  count++;
  if (t->lchild != nullptr) total = _getNextNode2(t->lchild, count, total);
  if (t->rchild != nullptr) total = _getNextNode2(t->rchild, count, total);

  return total;
}

int GetWPL2(binaryTree::BiTree t) {
  return t == nullptr ? 0 : _getNextNode2(t, 0, 0);
}
/*  解法2 ****/

void Test() {
  binaryTree::BiTree t;
//  binarySearchTree::CreateBST(t);
  binaryTree::CreateANewTree(t);
  std::cout << t_4_3_19::GetWPL2(t) << std::endl;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_19_H
