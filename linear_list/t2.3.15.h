//
// Created by schwarzeni on 2018/7/22.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_15_H
#define KAOYAN_DATA_STRUCTURE_T2_3_15_H

#include "link_list.h"
/**
 * 2018/7/22
 * p37
 * 求两个递增集合的并集
 * 测试：
 *  linearList::data = new int[5]{4, 6, 9, 10, 16};
    linearList::length = 5;
    linearList::LinkList l2;
    linearList::CreateListFromHead(l2);

    linearList::data = new int[10]{0, 1, 2, 3, 4, 5, 6, 16, 20, 29};
    linearList::length = 10;
    linearList::LinkList l1;
    linearList::CreateListFromHead(l1);

    t2_3_15::Intersection(l1, l2);
    linearList::DisplayLinkList(l1);
    linearList::DisplayLinkList(l2);
 */
namespace t2_3_15 {

void Intersection(linearList::LinkList &l1, linearList::LinkList &l2) {
  auto tmpL1 = l1;
  auto tmpL2 = l2;

  while (tmpL1->next != nullptr && tmpL2->next != nullptr) {
    if (tmpL1->next->data < tmpL2->next->data) {
      auto tmp = tmpL1->next;
      tmpL1->next = tmpL1->next->next;
      delete tmp;
    } else if (tmpL1->next->data > tmpL2->next->data) {
      tmpL2 = tmpL2->next;
    } else {
      tmpL1 = tmpL1->next;
      tmpL2 = tmpL2->next;
    }
  }

  // l1表未遍历完，释放剩余结点
  auto tmpL1tail = tmpL1->next;
  tmpL1->next = nullptr;
  while (tmpL1tail != nullptr) {
    auto tmp = tmpL1tail;
    tmpL1tail = tmpL1tail->next;
    delete tmp;
  }

  // 清空l2链表
  auto tmpL2tail = l2->next;
  l2->next = nullptr;
  while (tmpL2tail != nullptr) {
    auto tmp = tmpL2tail;
    tmpL2tail = tmpL2tail->next;
    delete tmp;
  }
}

// 求成并集了55555
//void Intersection(linearList::LinkList &l1, linearList::LinkList l2) {
//  auto tmpL1 = l1->next;
//  auto tmpL2 = l2->next;
//  linearList::LNode* l1tail = l1;
//
//  while (tmpL1 != nullptr && tmpL2 != nullptr) {
//
//    if (tmpL1->next == nullptr) l1tail = tmpL1;
//
//    if (tmpL1->data > tmpL2->data) {
//      auto tmp = tmpL2->next;
//      tmpL2->next = tmpL1->next;
//      tmpL1->next = tmpL2;
//
//      tmpL2 = tmp;
//    } else if (tmpL1->data < tmpL2->data) {
//      tmpL1 = tmpL1->next;
//    } else {
//      tmpL1 = tmpL1->next;
//      tmpL2 = tmpL2->next;
//    }
//  }
//
//  while (tmpL2 != nullptr) {
//    auto tmp = tmpL2->next;
//    l1tail->next = tmpL2;
//    tmpL2 = l1tail;
//    tmpL2->next = tmp;
//  }
//}

}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_15_H
