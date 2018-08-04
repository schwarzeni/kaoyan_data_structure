//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_20_H
#define KAOYAN_DATA_STRUCTURE_T2_3_20_H

#include "link_double_list.h"
/**
 * 2018/7/23
 * p37
 * 对非双向循环链表进行操作，并按操作的次数从大到小排序
 *
 * 测试数据:
 *  linkDoubleList::length = 9;
    linkDoubleList::data = new linkDoubleList::Elemtype[9]{1,2,3,4,5,6,7,8,9};
    linkDoubleList::LinkList l1;
    linkDoubleList::Init(l1);
    int data;
    while (true) {
      std::cin >> data;
      if (data == 0) break;
      t2_3_20::Locate(l1, data);
      linkDoubleList::Display(l1);
    }
 *
 */
namespace t2_3_20 {
void AccessFunc(linkDoubleList::LNode *&node) {
  node->freq += 1;
}

void Locate(linkDoubleList::LinkList &l, linkDoubleList::Elemtype x) {
  auto tmpNode = l->next;
  linkDoubleList::LNode *accessNode;
  auto isAccessNode = false;
  while (tmpNode != nullptr) {
    if (tmpNode->data == x) {
      accessNode = tmpNode;
      AccessFunc(tmpNode);
      isAccessNode = true;
      break;
    }
    tmpNode = tmpNode->next;
  }

  if (isAccessNode) {
    tmpNode = l->next;
    while (tmpNode != nullptr) {
      if (tmpNode->freq <= accessNode->freq && tmpNode != accessNode) {

        // TODO: 注意对双向链表移动的处理，移除 + 插入
        if (accessNode->next != nullptr) {
          accessNode->next->pred = accessNode->pred;
        }
        if (accessNode->pred != nullptr) {
          accessNode->pred->next = accessNode->next;
        }

        accessNode->pred = tmpNode->pred;
        accessNode->next = tmpNode;
        if (tmpNode->pred == nullptr) {
          l->next = accessNode;
        } else {
          tmpNode->pred->next = accessNode;
        }
        tmpNode->pred = accessNode;
        break;
      }
      tmpNode = tmpNode->next;
    }
  }

}

}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_20_H
