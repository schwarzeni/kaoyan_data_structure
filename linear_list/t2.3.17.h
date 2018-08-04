//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_17_H
#define KAOYAN_DATA_STRUCTURE_T2_3_17_H

#include "link_double_cycle_list.h"
/**
 * 2018/7/23
 * 判断循环双链表是否对称
 * p38
 *
 * 测试
 *  linkDoubleCycleList::length = 6;
    linkDoubleCycleList::data = new linkDoubleCycleList::Elemtype[6]{1, 2, 3, 3, 2, 1};
    linkDoubleCycleList::LinkList l;
    linkDoubleCycleList::Init(l);
    std::cout << t2_3_17::IsSymmetric(l) << std::endl;
 */
namespace t2_3_17 {
bool IsSymmetric(linkDoubleCycleList::LinkList l) {
  linkDoubleCycleList::LNode *head = l->next;
  linkDoubleCycleList::LNode *tail = l->prev;

  while (head != nullptr && tail != nullptr) {
    // 相遇，情况是指向相同地址（个数为奇数）或者临近地址（个数为偶数）
    if (head == tail || head->prev == tail) return true;

    // 不相等则返回false
    if (head->data != tail->data) return false;
    head = head->next;
    tail = tail->prev;
  }
  return true;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_17_H
