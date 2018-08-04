//
// Created by schwarzeni on 2018/7/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_2_10_H
#define KAOYAN_DATA_STRUCTURE_T2_2_10_H

#include "../util.h"
/**
 *  向左平移数组值
 *  p18 11
 *  测试数据
 *    auto *arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      for (int i = 1; i < 20; i++) {
        T2_2_10::MoveLeft(arr, 10, 1);
        util::PrintArray(arr, 10);
      }
 */
namespace T2_2_10 {
void reverse(int *arr, int startIdx, int length) {
  int endIdx = startIdx + length - 1;
  // TODO: 注意循环的各个参数 ！！！
  for (int i = startIdx; i < (startIdx + endIdx) / 2; i++) {
    int tmp = arr[i];
    arr[i] = arr[startIdx + endIdx - i];
    arr[startIdx + endIdx - i] = tmp;
  }
}

void MoveLeft(int arr[], int length, int moveLength) {
  moveLength = moveLength % length;
  T2_2_10::reverse(arr, 0, length);
  T2_2_10::reverse(arr, length - moveLength, moveLength);
  T2_2_10::reverse(arr, 0, length - moveLength);
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_2_10_H
