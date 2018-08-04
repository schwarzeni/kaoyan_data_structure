//
// Created by schwarzeni on 2018/7/23.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_3_16_H
#define KAOYAN_DATA_STRUCTURE_T2_3_16_H

#include "link_list.h"
/**
 * 2018/7/23
 * p38
 * 判断l2是否为l1的子序列
 *
 * 测试：
 *  linearList::data = new int[5]{4, 5, 6, 16, 20};
    linearList::length = 5;
    linearList::LinkList l1;
    linearList::CreateListFromHead(l1);

    linearList::data = new int[10]{0, 1, 2, 3, 4, 5, 6, 16, 20, 29};
    linearList::length = 10;
    linearList::LinkList l2;
    linearList::CreateListFromHead(l2);

    std::cout << t2_3_16::IsSubsquence(l2, l1) << std::endl;
 */
namespace t2_3_16 {
bool IsSubsquence(linearList::LinkList l1, linearList::LinkList l2) {
  auto startNode = l1->next;

  while (startNode != nullptr) {
    auto tmpNodel1 = startNode;
    auto tmpNodel2 = l2->next;

    while (tmpNodel1 != nullptr) {
      if (tmpNodel2 == nullptr) {
        return true;
      }
      if (tmpNodel1->data != tmpNodel2->data) break;
      tmpNodel1 = tmpNodel1->next;
      tmpNodel2 = tmpNodel2->next;
    }

    startNode = startNode->next;
  }
  return false;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_3_16_H
