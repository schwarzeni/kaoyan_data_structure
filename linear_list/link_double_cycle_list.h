//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_LINK_DOUBLE_CYCLE_LIST_H
#define KAOYAN_DATA_STRUCTURE_LINK_DOUBLE_CYCLE_LIST_H

#include <iostream>
/**
 * 2018/7/23
 * 循环双链表
 */
namespace linkDoubleCycleList {

int length = 10;
typedef int Elemtype;
Elemtype *data = new Elemtype[length]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

typedef struct LNode {
  Elemtype data;
  LNode *next;
  LNode *prev;
} LNode, *LinkList;

/**
 * 2018/7/23
 * 初始化循环链表
 * @param l
 */
void Init(LinkList &l) {

  l = new LNode{};
  l->prev = nullptr;
  l->next = nullptr;
  auto isFirst = true;

  for (int i = length - 1; i >= 0; i--) {
    auto node = new LNode{};
    node->data = data[i];

    // 当链表中只有一个元素的情况
    if (isFirst) {
      node->next = node;
      node->prev = node;
      l->prev = node;
      isFirst = false;
    } else {
      //TODO: !!!!!!! 注意对这两行的处理
      // 头指针的prev指向链表的尾部
      l->prev->next = node;
      // 头指针的next指向的元素的prev的指向
      l->next->prev = node;
      node->prev = l->prev;
      node->next = l->next;
    }
    l->next = node;
  }
}

/**
 * 2018/7/23
 * 正向输出
 * @param l
 * @param times
 */
void Display(LinkList l, int times) {
  if (l->next == nullptr) return;
  auto tmp = l->next;
  auto oneLineNum = 20;
  for (int i = 1; i <= times; i++) {
    std::cout << tmp->data << " " ;
    if (i % oneLineNum == 0) {
      std::cout << std::endl;
    }

    if (tmp->next == l->next) {
      std::cout << std::endl<< "=====" << std::endl;
    }

    tmp = tmp->next;
  }
  std::cout << std::endl;
}

/**
 * 2018/7/23
 * 反向输出
 * @param l
 * @param times
 */
void ReviseDisplay(LinkList l, int times) {
  if (l->next == nullptr) return;
  auto tmp = l->prev;
  auto oneLineNum = 20;
  for (int i = 1; i <= times; i++) {
    std::cout << tmp->data << " " ;
    if (i % oneLineNum == 0) {
      std::cout << std::endl;
    }

    if (tmp->prev == l->prev) {
      std::cout << std::endl<< "=====" << std::endl;
    }

    tmp = tmp->prev;
  }
  std::cout << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_LINK_DOUBLE_CYCLE_LIST_H
