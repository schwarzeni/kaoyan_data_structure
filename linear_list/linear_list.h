//
// Created by schwarzeni on 2018/7/17.
//

#ifndef KAOYAN_DATA_STRUCTURE_LINEAR_LIST_H
#define KAOYAN_DATA_STRUCTURE_LINEAR_LIST_H

#include <iostream>
namespace linearList {

typedef int DataType;

typedef struct {
  DataType *data;
  int length;
} SqList;

void PrintListData(SqList &l) {
  for (int i = 0; i < l.length; i++) {
    std::cout << l.data[i] << std::endl;
  }
}

/**
 *  2.2.3 p18 删除顺序表中的一个数据
 *  数据：
 *  linearList::SqList l{};
    l.data = new int[10]{3,2,3,3,3,6,7,3,4,3};
    l.length = 10;

    expected: [2,6,7,4]

    尽量减少数据交换的次数

 * @param l
 * @param value
 */
void DeleteValue(SqList &l, DataType value) {
  int resultIdx = 0;

  for (int i = 0; i < l.length; i++) {
    if (l.data[i] == value) {
      continue;
    } else {
      l.data[resultIdx] = l.data[i];
      resultIdx++;
    }
  }
  l.length = resultIdx;
}

/**
 *  2.2.6 p18 删除有序表中相同的元素
 *  数据
       linearList::SqList l{};
       l.data = new int[10]{1,1,2,2,2,3,3,4,5,5};
       l.length = 10;

       expected: [1,2,3,4,5]
 * @param l
 */
void DeleteOrderedListSame(SqList &l) {
  int resultIdx = 1;

  for (int i = 1; i < l.length; i++) {
    if (l.data[i - 1] == l.data[i]) {
      continue;
    } else {
      l.data[resultIdx] = l.data[i];
      resultIdx++;
    }
  }
  l.length = resultIdx;
}

/**
 * 2.2.8 p18 合并两个有序表
 * 数据
 *
 *  linearList::SqList l1{};
    l1.data = new int[6]{1,2,3,6,7,9};
    l1.length = 6;

    linearList::SqList l2{};
    l2.data = new int[6]{4,5,8};
    l2.length = 3;

    linearList::SqList l3{};

    expected [1,2,3,4,5,6,7,8,9]
 * @param l1
 * @param l2
 * @param l3
 */
void MergeOrderedLists(SqList l1, SqList l2, SqList &l3) {
  int totalLength = l1.length + l2.length;
  l3.data = new DataType[totalLength];
  l3.length = totalLength;

  int l1Idx = 0,
      l2Idx = 0,
      l3Idx = 0;

  while (l1Idx != l1.length && l2Idx != l2.length) {
    if (l1.data[l1Idx] > l2.data[l2Idx]) {
      l3.data[l3Idx] = l2.data[l2Idx];
      l3Idx++;
      l2Idx++;
    } else {
      l3.data[l3Idx] = l1.data[l1Idx];
      l1Idx++;
      l3Idx++;
    }
  }
  while (l1Idx < l1.length) {
    l3.data[l3Idx] = l1.data[l1Idx];
    l1Idx++;
    l3Idx++;
  }
  while (l2Idx < l2.length) {
    l3.data[l3Idx] = l2.data[l2Idx];
    l3Idx++;
    l2Idx++;
  }

}

/**
 *  二分查找
 *  代码
 *    linearList::SqList l{};
      l.data = new int[9]{1, 2, 3, 6, 7, 9, 11, 12, 16};
      l.length = 9;
      int idx = linearList::BinarySearch(l, 11);
 * @param l
 * @param data
 * @return
 */
int BinarySearch(SqList l, DataType data) {
  int left = 0,
      right = l.length - 1,
      mid = -1;

  while (left <= right) {
    mid = (left + right) / 2;
    if (l.data[mid] > data) {
      right = mid - 1;
    }
    if (l.data[mid] < data) {
      left = mid + 1;
    }
    if (l.data[mid] == data) {
      return mid;
    }
  }

  return -1;
}

}

#endif //KAOYAN_DATA_STRUCTURE_LINEAR_LIST_H
