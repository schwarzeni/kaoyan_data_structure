//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_2_4_H
#define KAOYAN_DATA_STRUCTURE_T2_2_4_H

#include "link_list.h"

/**
 *  2018/7/19
 *  p37
 *  删除链表中最小值的节点
 *    linearList::data = new int[10]{5, 4, 3, 5, 2, 6, 7, 8, 9, 10};
      linearList::LinkList l;
      linearList::CreateListFromHead(l);
      t2_3_4::DeleteMinValInLinkList(l);
      linearList::DisplayLinkList(l);
 */
namespace t2_3_4 {
/**
 * 删除链表中最小值的节点
 * @param l
 */
void DeleteMinValInLinkList(linearList::LinkList &l) {
  if (l->next == nullptr) return;
  if (l->next->next == nullptr) {
    delete l->next;
    l->next = nullptr;
    return;
  }

  linearList::LNode *minPrev = l->next;
  linearList::LNode *prev = l->next;
  linearList::LNode *curr = l->next->next;
  linearList::Elemtype minVal = l->next->data;

  while (curr != nullptr) {
    if (curr->data < minVal) {
      minPrev = prev;
      minVal = curr->data;
    }
    prev = curr;
    curr = curr->next;
  }

  curr = minPrev->next->next;
  delete minPrev->next;
  minPrev->next = curr;

}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_2_4_H
