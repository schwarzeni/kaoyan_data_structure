//
// Created by schwarzeni on 2018/7/18.
//

#ifndef KAOYAN_DATA_STRUCTURE_UTIL_H
#define KAOYAN_DATA_STRUCTURE_UTIL_H

#include <iostream>
namespace util {
void PrintArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << " ";
    if (i+1 % 15 == 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

void BreakLine() {
  std::cout << std::endl;
}
}

#endif //KAOYAN_DATA_STRUCTURE_UTIL_H
