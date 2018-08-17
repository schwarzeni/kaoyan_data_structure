//
// Created by schwarzeni on 2018/8/17.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_6_H
#define KAOYAN_DATA_STRUCTURE_T4_3_6_H

#include "binary_tree.h"
/**
 * 2018/8/17
 * p123
 * 给出先序遍历和中序遍历求其对应的二叉树
 * 1:24:57
 * 先序遍历数组：树的根结点在数组的第一位
 * 中序遍历数组：根结点前面都是左子树，后面都是右子树
 */
namespace t_4_3_6 {

typedef struct Array {
  binaryTree::ElemType *rawArray; // 原始数组
  int idx; // 子数组的第一位的idx
  int len; // 子数组的长度
} Array;

void _generateTree(binaryTree::BiTree &T, t_4_3_6::Array preArr, t_4_3_6::Array inArr) {
  T->data = preArr.rawArray[preArr.idx];

  int rootIdx = inArr.idx;
  for (; inArr.rawArray[rootIdx] != T->data; rootIdx++);

  int lLen = rootIdx - inArr.idx;
  int rLen = inArr.len - 1 - lLen;

  if (lLen > 0) {
    binaryTree::BiTree t;
    binaryTree::CreateNewNode(t, -1, nullptr, nullptr);
    T->lchild = t;
    t_4_3_6::_generateTree(t, Array{preArr.rawArray, preArr.idx + 1, lLen}, Array{inArr.rawArray, inArr.idx, lLen});
  }
  if (rLen > 0) {
    binaryTree::BiTree t;
    binaryTree::CreateNewNode(t, -1, nullptr, nullptr);
    T->rchild = t;
    t_4_3_6::_generateTree(t,
                           Array{preArr.rawArray, preArr.idx + lLen + 1, rLen},
                           Array{inArr.rawArray, rootIdx + 1, rLen});
  }
}

void GenerateTree(binaryTree::BiTree &T,
                  binaryTree::ElemType *preOrderArr,
                  binaryTree::ElemType *inOrderArr,
                  int len) {
  Array arr1{preOrderArr, 0, len};
  Array arr2{inOrderArr, 0, len};

  binaryTree::CreateNewNode(T, -1, nullptr, nullptr);
  t_4_3_6::_generateTree(T, arr1, arr2);
}

void Test() {
  auto *arr1 = new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto *arr2 = new int[9]{2, 3, 1, 5, 4, 7, 8, 6, 9};
  binaryTree::BiTree root;
  t_4_3_6::GenerateTree(root, arr1, arr2, 9);
  binaryTree::InOrder(root);
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_6_H
