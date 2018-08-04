//
// Created by schwarzeni on 2018/7/24.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_23_H
#define KAOYAN_DATA_STRUCTURE_T2_3_23_H

#include "link_list.h"
/**
 *  2018/7/24
 *  p37
 *  删除链表中绝对值相同的元素，保留第一个
 *  测试数据
 *
 *  linearList::length = 8;
    linearList::data = new int[linearList::length]{21, -15, -15, -7, 15, 7, 6, -6};
    linearList::LinkList l;
    linearList::CreateListFromHead(l);

    t2_3_23::DeleteSame(l);
    linearList::DisplayLinkList(l);
 */
namespace t2_3_23 {
void DeleteSame(linearList::LinkList &l) {
  auto *data = new int[linearList::length];

  if (l->next == nullptr || l->next->next == nullptr) return;

  auto tmpPrevNode = l->next;
  data[tmpPrevNode->data < 0 ? 0 - tmpPrevNode->data : tmpPrevNode->data] = 1;

  while (tmpPrevNode->next != nullptr) {

    int idx = tmpPrevNode->next->data < 0 ? 0 - tmpPrevNode->next->data : tmpPrevNode->next->data;
    if (data[idx] == 0) {
      data[idx] = 1;
      tmpPrevNode = tmpPrevNode->next;
    } else {
      // TODO: 注意，删除前驱元素的下一个元素之后其依然为下一个元素的先驱元素
      auto tmp = tmpPrevNode->next;
      tmpPrevNode->next = tmpPrevNode->next->next;
      delete tmp;
    }

  }
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_23_H
