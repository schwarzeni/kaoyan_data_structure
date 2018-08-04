//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_7_H
#define KAOYAN_DATA_STRUCTURE_T2_3_7_H

#include "link_list.h"
/**
 *  2018/7/19
 *  p37
 *  删除链表中介于两个值之间的所以节点
 *  O(n)
 *  测试代码
 *    linearList::data = new int[10]{9, 1, 8, 2, 7, 10, 6, 3, 5, 4};
    linearList::LinkList l;
    linearList::CreateListFromHead(l);
    t2_3_7::DeleteBetween(l, 4, 7);
    linearList::DisplayLinkList(l);
 */
namespace t2_3_7 {
void DeleteBetween(linearList::LinkList &l, linearList::Elemtype min, linearList::Elemtype max) {
  linearList::LNode *curr = l->next;
  linearList::LNode *prev = nullptr;
  linearList::LNode *tmp = nullptr;

  while (curr != nullptr) {

    if (curr->data >= min && curr->data <= max) {
      tmp = curr;
      if (prev == nullptr) {
        l->next = curr->next;
      } else {
        prev->next = curr->next;
      }
      delete tmp;
      curr = curr->next;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_7_H
