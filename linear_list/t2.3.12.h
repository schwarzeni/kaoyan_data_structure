//
// Created by schwarzeni on 2018/7/22.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_12_H
#define KAOYAN_DATA_STRUCTURE_T2_3_12_H

#include "link_list.h"

/**
 * 2018/7/22
 * p37
 * 删去顺序表中相同的数据
 * 测试数据
 *  linearList::data = new int[16]{0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5};
    linearList::length = 16;
    linearList::LinkList l;

    linearList::CreateListFromHead(l);
    t2_3_12::RemoveSameItem(l);

    linearList::DisplayLinkList(l);
 */
namespace t2_3_12 {
void RemoveSameItem(linearList::LinkList &l) {
  if (l->next == nullptr) return;
  auto curentValue = l->next->data;
  auto tmpNode = l->next;
  while (tmpNode->next != nullptr) {

    if (tmpNode->next->data == curentValue) {
      auto tmp = tmpNode->next;
      tmpNode->next = tmpNode->next->next;
      delete tmp;
    } else {
      // 不相等再进行->next操作
      curentValue = tmpNode->next->data;
      tmpNode = tmpNode->next;
    }

  }
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_12_H
