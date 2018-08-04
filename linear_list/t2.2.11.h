//
// Created by schwarzeni on 2018/7/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_T2_2_11_H
#define KAOYAN_DATA_STRUCTURE_T2_2_11_H

/**
 *  寻找两个等长序列的中位数
 *  p18 12
 *
 *  测试数据
 *  int len = 5;
    auto *arr1 = new int[len]{1, 2, 3, 9, 10};
    auto *arr2 = new int[len]{4, 5, 6, 7, 8};
    int midNum = T2_2_11::GetMiddleNumber(arr1, arr2, len);
    std::cout << midNum << std::endl;
 */
namespace T2_2_11 {
int GetMiddleNumber(const int arr1[], const int arr2[], int len) {
  int arr1Idx = 0;
  int arr2idx = 0;
  int currIdx = 0;
  int midNum = 0;

  while (currIdx != len) {
    if (arr1[arr1Idx] < arr2[arr2idx]) {
      midNum = arr1[arr1Idx];
      arr1Idx++;
    } else {
      midNum = arr2[arr2idx];
      arr2idx++;
    }
    currIdx++;
  }

  return midNum;
}
}

#endif //KAOYAN_DATA_STRUCTURE_T2_2_11_H
