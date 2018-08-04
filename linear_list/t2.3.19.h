//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_19_H
#define KAOYAN_DATA_STRUCTURE_T2_3_19_H

#include "link_cycle_list.h"
/**
 * 2018/7/23
 * p38
 * 按升序删除链表结点
 * 测试数据
 *
 *  linkCycleList::length = 9;
    linkCycleList::data = new linkCycleList::Elemtype[9]{1, 2, 3, 3, 2, 1, 6, 0, 2};
    linkCycleList::LinkList l1;
    linkCycleList::Init(l1);

    t2_3_19::DeleteMins(l1);
 */
namespace t2_3_19 {
void DeleteMins(linkCycleList::LinkList &l) {
  // 链表长度为0，则不作处理
  if (l->next == nullptr) return;

  while (true) {
    // 遍历用指针
    auto tmpPrevNode = l->next;
    // 退出循环条件：链表长度为1
    if (l->next == l->next->next) break;

    auto min = tmpPrevNode->next->data;
    // 结点的前驱结点
    auto minNodePrev = tmpPrevNode;
    // 完成一次遍历
    do  {
      if (min > tmpPrevNode->next->data) {
        min = tmpPrevNode->next->data;
        minNodePrev = tmpPrevNode;
      }
      tmpPrevNode = tmpPrevNode->next;
    } while (tmpPrevNode != l->next);

    auto deleteNode = minNodePrev->next;
    if (l->next == deleteNode) {
      l->next = deleteNode->next;
    }
    minNodePrev->next = minNodePrev->next->next;
    delete deleteNode;

    std::cout << min << " ";
  }
  std::cout << l->next->data << std::endl;
  delete l->next;
  delete l;

}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_19_H
