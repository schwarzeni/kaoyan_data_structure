//
// Created by schwarzeni on 2018/7/24.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_21_H
#define KAOYAN_DATA_STRUCTURE_T2_3_21_H

#include "link_list.h"
/**
 * 2018/7/24
 * p37
 * 以最快的方式找到倒序第k个元素
 * 测试数据
 *    linearList::data = new int[linearList::length]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      linearList::LinkList l;
      linearList::CreateListFromHead(l);

      int data = -1;
      t2_3_21::FindByReverseIdTrueAnswer(l, &data, 5);
      std::cout << data << std::endl;
 */
namespace t2_3_21 {
/**
 * 2018/7/24
 * 自己的方法：先遍历一遍算出链表的长度，在根据长度与倒序k个的关系再遍历一遍找到第len-k个元素
 */
int FindByReverseId(linearList::LinkList l, linearList::Elemtype *data, int id) {

  if (id <= 0) return 0;

  auto tmpNode = l->next;
  int length = 0;

  // 计算链表的长度
  while (tmpNode != nullptr) {
    tmpNode = tmpNode->next;
    length++;
  }

  // 超出的链表的长度，返回0
  if (length < id) return 0;

  tmpNode = l->next;
  int count = 0;
  int expectedIdx = length - id;
  while (count != expectedIdx) {
    tmpNode = tmpNode->next;
    count++;
  }

  *data = tmpNode->data;
  return 1;
}
/**
 * 2018/7/24
 * 答案的方法：直接设置两个指针，一个指针先开始遍历，当遍历到第id个的时候，第二个指针才开始遍历
 */
int FindByReverseIdTrueAnswer(linearList::LinkList l, linearList::Elemtype *data, int id) {
  auto tmpP1 = l->next;
  auto tmpP2 = l->next;
  int count = 0;
  int reverseId = 0;

  while (tmpP1 != nullptr) {
    tmpP1 = tmpP1->next;
    if (count >= id) {
      tmpP2 = tmpP2->next;
      reverseId++;
    }
    count++;
  }

  if (reverseId + id != count) return 0;
  *data = tmpP2->data;
  return 1;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_21_H
