//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_LINK_DOUBLE_LIST_H
#define KAOYAN_DATA_STRUCTURE_LINK_DOUBLE_LIST_H

#include <iostream>
/**
 * 2018/7/23
 * 非循环双向链表
 */
namespace linkDoubleList {
int length = 10;
typedef int Elemtype;
Elemtype *data = new Elemtype[length]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

typedef struct LNode {
  Elemtype data;
  int freq;
  LNode *next;
  LNode *pred;
} LNode, *LinkList;

/**
 * 2018/7/23
 * 初始化操作
 * @param l
 */
void Init(LinkList &l) {
  l = new LNode{};
  l->next = nullptr;
  for (int i = length - 1; i >= 0; i--) {
    auto newNode = new LNode{};
    newNode->data = data[i];
    newNode->freq = 0;
    if (l->next != nullptr) {
      l->next->pred = newNode;
    }
    newNode->pred = nullptr;
    newNode->next = l->next;
    l->next = newNode;
  }
}

/**
 * 2018/7/23
 * 打印链表
 * @param l
 */
void Display(LinkList l) {
  auto tmp = l->next;
//  LNode* prev = nullptr;
  while (tmp != nullptr) {
    std::cout << "(" << tmp->data << ": " << tmp->freq << ") ";

//    if (tmp->next == nullptr) {
//      prev = tmp;
//    }
    tmp = tmp->next;
  }

  std::cout << std::endl;

//  while (prev != nullptr) {
//    std::cout << "(" << prev->data << ": " << prev->freq << ") ";
//    prev = prev->pred;
//  }


}

}

#endif //KAOYAN_DATA_STRUCTURE_LINK_DOUBLE_LIST_H
