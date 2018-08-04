//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_6_H
#define KAOYAN_DATA_STRUCTURE_T2_3_6_H

#include "link_list.h"
/**
 *  2018/7/19
 *  p37
 *  对链表的数据进行升序排序
 *  O(n^2)
 *  测试函数
 *    linearList::data = new int[10]{9, 1, 8, 2, 7, 10, 6, 3, 5, 4};
      linearList::LinkList l;
      linearList::CreateListFromHead(l);
      t2_3_6::SortLinkList(l);
      linearList::DisplayLinkList(l);
 */
namespace t2_3_6 {

void InsertVal(linearList::LinkList &l, linearList::LNode *n) {
  linearList::LNode *curr = l->next;
  bool moveFlag = false;
  linearList::Elemtype prevdata = n->data;
  linearList::Elemtype tmp;
  while (curr != n) {
    if (moveFlag) {
      tmp = curr->data;
      curr->data = prevdata;
      prevdata = tmp;
    } else if (curr->data > n->data) {
      moveFlag = true;
      tmp = curr->data;
      curr->data = n->data;
      prevdata = tmp;
    }
    curr = curr->next;
  }
  n->data = prevdata;
}

void SortLinkList(linearList::LinkList &l) {
  linearList::LNode* curr = l->next;
  while (curr != nullptr) {
    InsertVal(l, curr);
    curr = curr->next;
  }
}

}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_6_H
