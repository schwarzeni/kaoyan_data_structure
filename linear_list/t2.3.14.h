//
// Created by schwarzeni on 2018/7/22.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_14_H
#define KAOYAN_DATA_STRUCTURE_T2_3_14_H

#include "link_list.h"
/**
 * 2018/7/22
 * p37
 * 将两个递增链表中相同的元素生成一个新链表
 *
 * 测试
 *  linearList::data = new int[7]{0, 2, 4, 6, 7, 8, 9};
    linearList::length = 7;
    linearList::LinkList l1;
    linearList::CreateListFromHead(l1);

    linearList::data = new int[10]{1, 2, 2, 2, 6, 6, 7, 7, 9, 10};
    linearList::length = 10;
    linearList::LinkList l2;
    linearList::CreateListFromHead(l2);

    linearList::LinkList l;
    t2_3_14::GenerateSame(l1, l2, l);
    linearList::DisplayLinkList(l);
 */
namespace t2_3_14 {
void GenerateSame(linearList::LinkList l1, linearList::LinkList l2, linearList::LinkList &l) {
  if (l1->next == nullptr) return;

  l = new linearList::LNode{};
  l->next = nullptr;

  auto tmpL1 = l1->next;
  auto tmpL2 = l2->next;
  // 标记当前的数值是否已经匹配过
  bool hasmatch = false;

  while (tmpL1 != nullptr && tmpL2 != nullptr) {
    if (tmpL1->data > tmpL2->data) {
      hasmatch = false;
      tmpL2 = tmpL2->next;
    } else if (tmpL1->data < tmpL2->data) {
      hasmatch = false;
      tmpL1 = tmpL1->next;
    } else if (tmpL1->data == tmpL2->data && !hasmatch) {
      auto tmp = new linearList::LNode{};
      tmp->data = tmpL1->data;
      tmp->next = l->next;
      l->next = tmp;
      tmpL1 = tmpL1->next;
      tmpL2 = tmpL2->next;
      hasmatch = true;
    } else {
      tmpL1 = tmpL1->next;
      tmpL2 = tmpL2->next;
    }
  }
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_14_H
