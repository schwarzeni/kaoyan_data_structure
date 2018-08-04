//
// Created by schwarzeni on 2018/7/19.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_10_H
#define KAOYAN_DATA_STRUCTURE_T2_3_10_H

#include "link_list.h"
/**
 * 2018/7/19
 * p37
 * 将一个链表中奇偶项分别生成一个链表
 * 测试数据
 *
 *    linearList::data = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      linearList::LinkList l;
      linearList::LinkList odd;
      linearList::LinkList even;
      linearList::CreateListFromHead(l);

      t2_3_10::DivideList(l, odd, even);
      linearList::DisplayLinkList(odd);
      linearList::DisplayLinkList(even);
 */
namespace t2_3_10 {

/**
 * 2018/7/19
 * 初始化
 * @param l
 * @param tail
 */
void CreateListHead(linearList::LinkList &l, linearList::LNode *&tail) {
  // 头指针和尾指针指向一个区域
  l = new linearList::LNode{};
  tail = l;
}

/**
 * 2018/7/19
 * 创建一个新节点
 * @param value
 * @return
 */
linearList::LNode* NewNode(linearList::Elemtype value) {
  auto *node = new linearList::LNode{};
  node->data = value;
  node->next = nullptr;
  return node;
}

void DivideList(linearList::LinkList &l, linearList::LinkList &odd_l, linearList::LinkList &even_l) {
  linearList::LNode *odd_l_tail = nullptr;
  linearList::LNode *even_l_tail = nullptr;
  linearList::LNode *curr = l->next;
  int count = 0;

  CreateListHead(odd_l, odd_l_tail);
  CreateListHead(even_l, even_l_tail);


  while (curr != nullptr) {
    linearList::LNode *newNode = NewNode(curr->data);
    // 偶
    if (count % 2 == 0) {
      even_l_tail->next = newNode;
      even_l_tail = newNode;
    }
    //奇
    else {
      odd_l_tail->next = newNode;
      odd_l_tail = newNode;
    }
    count++;
    curr = curr->next;
  }
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_10_H
