//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_LINK_CYCLE_LIST_H
#define KAOYAN_DATA_STRUCTURE_LINK_CYCLE_LIST_H

/**
 * 2018/7/23
 * 单向循环链表
 */
#include <iostream>
namespace linkCycleList {
int length = 5;
typedef int Elemtype;
Elemtype *data = new Elemtype[length]{1, 2, 3, 4, 5};

typedef struct LNode {
  Elemtype data;
  LNode *next;
} LNode, *LinkList;

/**
 * 2018/7/23
 * 初始化链表
 * @param l
 */
void Init(LinkList &l) {
  l = new LNode{};
  l->next = nullptr;
  bool isFirst = true;
  LNode* tail = nullptr;

  for (int i = length - 1; i >= 0; i--) {
    auto node = new LNode{};
    node->data = data[i];
    node->next = l->next;
    l->next = node;

    if (isFirst) {
      tail = node;
      isFirst = false;
    } else {
      tail->next = node;
    }
  }
}

/**
 * 2018/7/23
 * 正向输出列表值
 * @param l
 * @param times
 */
void Display(LinkList &l, int times) {
  if (l->next == nullptr) return;
  auto tmp = l->next;
  auto oneLineNum = 20;
  for (int i = 1; i <= times; i++) {
    std::cout << tmp->data << " " ;

    if (tmp->next == l->next) {
      std::cout << std::endl<< "=====" << std::endl;
    }

    tmp = tmp->next;
  }
  std::cout << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_LINK_CYCLE_LIST_H
