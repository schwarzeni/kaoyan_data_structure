//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_1_H
#define KAOYAN_DATA_STRUCTURE_T2_3_1_H

/**
 *  2018/7/19
 *  p37 递归算法，删除不带头节点的链表中所以值为x的点
 *  测试数据
 *    linearList::data = new int[linearList::length]{1, 2, 3, 3, 4, 5, 3, 3, 9, 3};
      linearList::LinkList l;
      linearList::CreateListFromHead(l);
      linearList::DisplayLinkList(l);
      t2_3_1::DeleteLinkListValue(l->next, 3);
      linearList::DisplayLinkList(l);
 */
#include "link_list.h"
namespace t2_3_1 {
void DeleteLinkListValue(linearList::LNode* &node, linearList::Elemtype value) {
  linearList::LNode *tmp;
  if (node == nullptr) return;

  if (node->data == value) {
    tmp = node;
    node = node->next;
    // TODO node为引用类型，直接对原链表进行操作，不会造成链表断链
    delete tmp;
    DeleteLinkListValue(node, value);
  } else {
    DeleteLinkListValue(node->next, value);
  }
}
}
#endif //KAOYAN_DATA_STRUCTURE_T2_3_1_H
