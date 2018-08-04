//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_18_H
#define KAOYAN_DATA_STRUCTURE_T2_3_18_H

#include "link_cycle_list.h"
/**
 *  2018/7/23
 *  p38
 *  两个单向循环链表，将l2接到l1之后，保持循环的特性
 *
 *  测试数据
 *    linkCycleList::length = 6;
      linkCycleList::data = new linkCycleList::Elemtype[6]{1, 2, 3, 3, 2, 1};
      linkCycleList::LinkList l1;
      linkCycleList::Init(l1);

      linkCycleList::length = 5;
      linkCycleList::data = new linkCycleList::Elemtype[5]{6, 7, 8, 9, 10};
      linkCycleList::LinkList l2;
      linkCycleList::Init(l2);

      t2_3_18::Concat(l1, l2);
      linkCycleList::Display(l1, 22);
 */
namespace t2_3_18 {
void Concat(linkCycleList::LinkList &l1, linkCycleList::LinkList &l2) {
  // 遍历链表使用的指针
  auto tmp = l1->next;

  // 如果头指针l1指向的下一个为空，则直接把l2赋给l1
  if (tmp == nullptr) {
    delete l1;
    l1 = l2;
    return;
  }

  // 如果头指针l2指向的下一个为空，则直接返回，不作处理
  if (l2->next == nullptr) return;

  // 遍历到l1的最后一个
  while (tmp->next != l1->next) {
    tmp = tmp->next;
  }

  // 连接
  tmp->next = l2->next;

  // 遍历到l2的最后一个
  while (tmp->next->next != l2->next) {
    tmp = tmp->next;
  }

  // 完成循环链表
  tmp->next->next = l1->next;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_18_H
