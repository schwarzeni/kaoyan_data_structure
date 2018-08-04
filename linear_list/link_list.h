//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_LINK_LIST_H
#define KAOYAN_DATA_STRUCTURE_LINK_LIST_H

#include <iostream>
namespace linearList {
typedef int Elemtype;

int length = 10;
int *data = new int[length]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/**
 *  2018/7/19
 *  节点结构
 */
typedef struct LNode {
  Elemtype data;
  struct LNode *next;
} LNode, *LinkList;

/**
 *  2018/7/19
 *  初始化链表头插法
 * @param L
 * @return
 */
LinkList CreateListFromHead(LinkList &L) {
  LNode *node;
  L = new LNode{};
  L->next = nullptr;

  for (int i = length - 1; i >= 0; i--) {
    node = new LNode{};
    node->data = data[i];
    node->next = L->next;
    L->next = node;
  }
  return L;
}

LinkList CreateListFromTail(LinkList &L) {
  LNode *node;
  L = new LNode{};
  L->next = nullptr;

  LNode *lastNode = L;

  for (int i = 0; i < length; i++) {
    node = new LNode{};
    node->data = data[i];
    node->next = nullptr;
    lastNode->next = node;
    lastNode = node;
  }

  return L;
}

/**
 * 2018/7/19
 * 输出链表数据
 * @param L
 */
void DisplayLinkList(LinkList &L) {
  LNode* tmp = L->next;
  int count = 1;
  while (tmp != nullptr) {
    std::cout << tmp->data << " ";
    if (count % 20 == 0) {
      std::cout << std::endl;
    }
    tmp = tmp->next;
    count++;
  }
  std::cout << std::endl;
}

}

#endif //KAOYAN_DATA_STRUCTURE_LINK_LIST_H
