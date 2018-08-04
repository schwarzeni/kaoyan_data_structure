//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_3_H
#define KAOYAN_DATA_STRUCTURE_T2_3_3_H

#include "link_list.h"

/**
 * 2018/7/19
 *  p37 反向输出链表对值
 *
 *  linearList::LinkList l;
    linearList::CreateListFromHead(l);
    t2_3_3::PrintReverse(l);
    linearList::DisplayLinkList(l);
 */
namespace t2_3_3 {

/**
 * 2018/7/19
 * 反转链表
 * @param l
 */
void ReverseLinkList(linearList::LinkList &l) {
  linearList::LNode *curr = l->next;
  linearList::LNode *prev = nullptr;

  while (curr != nullptr) {
    linearList::LNode *tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  l->next = prev;
}

/**
 * 2018/7/19
 * 反向打印链表数据
 * @param l
 */
void PrintReverse(linearList::LinkList &l) {
  ReverseLinkList(l);
  linearList::DisplayLinkList(l);
  ReverseLinkList(l);
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_3_H
