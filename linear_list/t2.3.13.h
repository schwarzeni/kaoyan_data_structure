//
// Created by schwarzeni on 2018/7/22.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_13_H
#define KAOYAN_DATA_STRUCTURE_T2_3_13_H

#include "link_list.h"

/**
 * 2018/7/22
 * p37
 * 合并两个递增列表为一个递减列表，结点使用原有的结点
 *
 * 测试
 *  linearList::data = new int[7]{0, 2, 4, 6, 7, 8, 9};
    linearList::length = 7;
    linearList::LinkList l1;
    linearList::CreateListFromHead(l1);

    linearList::data = new int[4]{1, 3, 5, 10};
    linearList::length = 4;
    linearList::LinkList l2;
    linearList::CreateListFromHead(l2);

    linearList::LinkList l;
    t2_3_13::MergeLinkList(l1, l2, l);
    linearList::DisplayLinkList(l);
 */
namespace t2_3_13 {
void InsertNext(linearList::LinkList &l, linearList::LNode *node) {
  node->next = l->next;
  l->next = node;
}

void MergeLinkList(linearList::LinkList &l1, linearList::LinkList &l2, linearList::LinkList &l) {
  l = new linearList::LNode{};
  l->next = nullptr;

  auto tmpL1 = l1->next;
  auto tmpL2 = l2->next;
  linearList::LNode* tmp;

  while (tmpL1 != nullptr && tmpL2 != nullptr) {
    if (tmpL1->data > tmpL2->data) {
      tmp = tmpL2->next;
      InsertNext(l, tmpL2);
      tmpL2 = tmp;
    } else {
      tmp = tmpL1->next;
      InsertNext(l, tmpL1);
      tmpL1 = tmp;
    }
  }

  while (tmpL1 != nullptr) {
    tmp = tmpL1->next;
    InsertNext(l, tmpL1);
    tmpL1 = tmp;
  }
  while (tmpL2 != nullptr) {
    tmp = tmpL2->next;
    InsertNext(l, tmpL2);
    tmpL2 = tmp;
  }
}
}
#endif //KAOYAN_DATA_STRUCTURE_T2_3_13_H
