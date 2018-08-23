//
// Created by schwarzeni on 2018/8/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T4_3_20_H
#define KAOYAN_DATA_STRUCTURE_T4_3_20_H

#include "binary_tree.h"
/**
 * 2018/8/23
 * p124
 * 输出中缀表达式
 * 思路
 *  后续遍历，做出相应处理即可
 */
namespace t_4_3_20 {
std::string _getSign(int sign) {
  std::string str = "";
  switch (sign) {
    case 0:str += "+";
      break;
    case 1:str = "-";
      break;
    case 2:str = "*";
      break;
    case 3:str = "/";
      break;
    default:char tmp = char(sign + '0' - 0);
      str += tmp;
  }
  return str;
}

void _init(binaryTree::BiTree &t) {
  binaryTree::BiTree tmp;
  binaryTree::BiTree tt;
  binaryTree::CreateNewNode(tt, 2, nullptr, nullptr);
  binaryTree::CreateNewNode(tmp, 0, nullptr, nullptr);
  tt->lchild = tmp;
  binaryTree::CreateNewNode(tmp, 2, nullptr, nullptr);
  tt->rchild = tmp;
  t = tt;
  tt = tt->lchild;
  binaryTree::CreateNewNode(tmp, 'a' - '0', nullptr, nullptr);
  tt->lchild = tmp;
  binaryTree::CreateNewNode(tmp, 'b' - '0', nullptr, nullptr);
  tt->rchild = tmp;
  tt = t;
  tt = tt->rchild;
  binaryTree::CreateNewNode(tmp, 'c' - '0', nullptr, nullptr);
  tt->lchild = tmp;
  binaryTree::CreateNewNode(tmp, 1, nullptr, nullptr);
  tt->rchild = tmp;
  binaryTree::CreateNewNode(tmp, 'd' - '0', nullptr, nullptr);
  tt->rchild->rchild = tmp;
}

std::string _processNode(binaryTree::BiTree t, std::string str) {

  // 为空，直接返回即可
  if (t == nullptr) return str;

  // 存在孩子结点，作出处理
  if (t->lchild != nullptr || t->rchild != nullptr) {
    str.append("(");
    str = _processNode(t->lchild, str);
    str.append(_getSign(t->data));
    str = _processNode(t->rchild, str);
    str.append(")");
  }

  // 孩子结点，直接输出
  if (t->lchild == nullptr && t->rchild == nullptr) {
    str.append(_getSign(t->data));
    return str;
  }

  return str;
}

std::string GetStr(binaryTree::BiTree t) {
  std::string str;
  return _processNode(t, str);
}

void Test() {
  binaryTree::BiTree t;
  t_4_3_20::_init(t);
  std::cout << t_4_3_20::GetStr(t) << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_T4_3_20_H
