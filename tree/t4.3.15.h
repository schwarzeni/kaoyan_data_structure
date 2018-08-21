//
// Created by schwarzeni on 2018/8/21.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_15_H
#define KAOYAN_DATA_STRUCTURE_T4_3_15_H

#include "binary_tree.h"
#include "../util.h"
/**
 * 2018/8/21
 * p123
 * 对于一个满二叉树，根据所给的先序序列生成后序序列
 * 思路
 *  根据规律直接对数组进行操作
 */
namespace t_4_3_15 {
void _postArr(binaryTree::ElemType *preArr, int idx, int len) {
  if (len > 3) {
    _postArr(preArr, idx + 1, len / 2);
    _postArr(preArr, idx + len / 2 + 1, len / 2);
  }

  auto head = preArr[idx];
  for (int i = idx + 1; i < idx + len; i++) {
    preArr[i - 1] = preArr[i];
  }
  preArr[len + idx - 1] = head;
}

void PostArr(binaryTree::ElemType *preArr, int len) {
  t_4_3_15::_postArr(preArr, 0, len);
}

void Test() {
  binaryTree::ElemType arr[] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
  t_4_3_15::PostArr(arr, 15);
  util::PrintArray(arr, 15);

  binaryTree::ElemType arr2[] = {1, 2, 4, 5, 3, 6, 7};
  t_4_3_15::PostArr(arr2, 7);
  util::PrintArray(arr2, 7);

  binaryTree::ElemType arr3[] = {0, 1, 2, 3, 4, 5, 6};
  t_4_3_15::PostArr(arr3, 7);
  util::PrintArray(arr3, 7);
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_15_H
