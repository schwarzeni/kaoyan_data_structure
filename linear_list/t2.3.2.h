//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_2_H
#define KAOYAN_DATA_STRUCTURE_T2_3_2_H

#include "link_list.h"

/**
 *  2018/7/19
 *  p37 删除链表中所以值为x的点
 *  测试数据
 *    linearList::data = new int[linearList::length]{1, 2, 3, 3, 4, 5, 3, 3, 9, 3};
      linearList::LinkList l;
      linearList::CreateListFromHead(l);
      linearList::DisplayLinkList(l);
      t2_3_2::DeleteLinkListValue(l->next, 3);
      linearList::DisplayLinkList(l);
 */

namespace t2_3_2 {
void DeleteLinkListValue(linearList::LinkList &l, int value) {
  linearList::LNode *prev;
  linearList::LNode *curr;
  prev = l;
  curr = l->next;

  while(curr != nullptr) {
    if (value == curr->data) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }

}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_2_H
