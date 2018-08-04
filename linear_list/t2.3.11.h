//
// Created by schwarzeni on 2018/7/22.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_11_H
#define KAOYAN_DATA_STRUCTURE_T2_3_11_H

/**
 *  2018/7/22
 *  p37
 *  拆分链表
 *  {a1, b1, a2, b2, ..., an, bn} -> {a1, a2, ..., an}, {bn, ..., b2, b1}
 *
 *  测试数据
 *    linearList::data = new int[16]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
      linearList::length = 16;
      linearList::LinkList l;
      linearList::LinkList l1;
      linearList::LinkList l2;
      linearList::CreateListFromHead(l);

      t2_3_11::SplitLinkList(l, l1, l2);
      linearList::DisplayLinkList(l1);
      linearList::DisplayLinkList(l2);
 *
 */
#include "link_list.h"
namespace t2_3_11 {

linearList::LNode* InsertToNext(linearList::LinkList &l, linearList::Elemtype data) {
  auto *node = new linearList::LNode{};
  node->data = data;
  node->next = l->next;
  l->next = node;
  return node;
}

void SplitLinkList(linearList::LinkList &l, linearList::LinkList &l1, linearList::LinkList &l2) {
  l1 = new linearList::LNode{};
  l1->next = nullptr;
  auto l1tail = l1;

  l2 = new linearList::LNode{};
  l2->next = nullptr;

  auto tmpNode = l->next;
  auto count = 0;
  while (tmpNode != nullptr) {
    if (count % 2 == 0) {
      auto tmp = InsertToNext(l1tail, tmpNode->data);
      l1tail = tmp;
    } else {
      InsertToNext(l2, tmpNode->data);
    }
    count++;
    tmpNode = tmpNode->next;
  }
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_11_H
