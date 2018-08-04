#include <iostream>
#include "tree/binary_tree.h"
#include "util.h"

int main() {
  binaryTree::BiTree T;
  binaryTree::CreateANewTree(T);
  binaryTree::LevelOrder(T);
}

