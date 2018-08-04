//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_9_H
#define KAOYAN_DATA_STRUCTURE_T2_3_9_H
#include "link_list.h"
/**
 *  2018/7/17
 *  p37
 *  按升序删除元素，并释放所占空间
 *  测试数据
 *
 *    linearList::data = new int[10]{9, 1, 8, 2, 7, 10, 6, 3, 5, 4};
      linearList::LinkList l;
      linearList::CreateListFromHead(l);
      t2_3_9::OrderlyPrintLinkList(l);
 */
namespace t2_3_9 {

/**
 * 2018/7/19
 * 打印数据
 * @param node
 */
void PrintData(linearList::LNode *node) {
  std::cout << node->data << std::endl;
}

/**
 * 2018/7/19
 * 删除最小项
 * @param l
 */
void DeleteSmallest(linearList::LinkList &l) {
  linearList::LNode *curr = nullptr;
  linearList::LNode *prev = nullptr;
  linearList::LNode *tmp = nullptr;
  linearList::Elemtype smalllest;
  linearList::LNode *smalllestPrev;

  // 处理一些特殊情况，长度为0或1
  if (l->next == nullptr) return;
  if (l->next->next == nullptr) {
    PrintData(l->next);
    delete l->next;
    l->next = nullptr;
    return;
  }

  smalllest = l->next->data;
  smalllestPrev = l;
  curr = l->next->next;
  prev = l->next;
  while (curr != nullptr) {
    if (curr->data < smalllest) {
      smalllestPrev = prev;
      smalllest = curr->data;
    }
    prev = curr;
    curr = curr->next;
  }

  // 删除找到的最小项
  tmp = smalllestPrev->next;
  PrintData(tmp);
  smalllestPrev->next = smalllestPrev->next->next;
  delete tmp;
}

void OrderlyPrintLinkList(linearList::LinkList &l) {
  while (l->next != nullptr) {
    DeleteSmallest(l);
  }
  delete l;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_9_H
