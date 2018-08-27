//
// Created by schwarzeni on 2018/8/27.
//

#ifndef KAOYAN_DATA_STRUCTURE_ADJACENCY_MATRIX_H
#define KAOYAN_DATA_STRUCTURE_ADJACENCY_MATRIX_H

#include <iostream>
namespace adjacencyMatrix {
#define MaxVertexNum 100
typedef int VertexType;
typedef int EdgeType;
typedef struct {
  VertexType Vex[MaxVertexNum];
  EdgeType Edge[MaxVertexNum][MaxVertexNum];
  int vexnum, arcnum;
} MGraph;

/**
 * 2018/8/27
 * 初始化
 *        v0
 *       /  \
 *      v1   v2
 *     / \  /  \
 *    v3  v4---v5
 */
void Init(MGraph *&G) {
  G = new MGraph{};
  G->vexnum = 6;
  G->arcnum = 7;
  int i = 0;
  for (; i < G->vexnum; i++) {
    G->Vex[i] = i;
    for (int j = 0; j < G->vexnum; j++) {
      G->Edge[i][j] = 0;
    }
  }
  G->Edge[0][1] = G->Edge[1][0] = 1;
  G->Edge[0][2] = G->Edge[2][0] = 1;
  G->Edge[1][3] = G->Edge[3][1] = 1;
  G->Edge[1][4] = G->Edge[4][1] = 1;
  G->Edge[2][4] = G->Edge[4][2] = 1;
  G->Edge[2][5] = G->Edge[5][2] = 1;
  G->Edge[4][5] = G->Edge[5][4] = 1;
}

void _visit(VertexType v, int idx) {
  std::cout << "( " << v << ", " << idx << ") ";
}

bool visited[MaxVertexNum];

/**
 * 广度优先
 * 2018/8/27
 * 注意点：1 广度优先前先验证结点是否已经访问过了
 *        2 在如队列的时候将visited数值设为true，以免重复访问
 */
void _bfs(MGraph *G, int idx) {
  if (visited[idx]) return;
  visited[idx] = true;
  auto *queue = new int[1000];
  int head = -1;
  int tail = -1;
  queue[++tail] = idx;
  visited[idx] = true;
  while (tail != head) {
    int cur = queue[++head];
    _visit(G->Vex[cur], cur);
    for (int i = 0; i < G->vexnum; i++) {
      if (!visited[i] && G->Edge[cur][i] != 0) {
        queue[++tail] = i;
        visited[i] = true;
      }
    }
  }
}
void BFSTraverse(MGraph *G) {
  for (int i = 0; i < G->vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G->vexnum; i++)
    _bfs(G, i);
}

/**
 * 深度优先，非递归
 * 2018/8/27
 */
void _dfs(MGraph *G, int idx) {
  if (visited[idx]) return;
  auto *stack = new int[1000];
  int stop = -1;
  stack[++stop] = idx;
  visited[idx] = true;
  while (stop != -1) {
    int cur = stack[stop--];
    _visit(G->Vex[cur], cur);
    for (int i = G->vexnum - 1; i >= 0; i--) {
      if (!visited[i] && G->Edge[cur][i] != 0) {
        stack[++stop] = i;
        visited[i] = true;
      }
    }
  }
}
void DFSTraverse(MGraph *G) {
  for (int i = 0; i < G->vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G->vexnum; i++)
    _dfs(G, i);
}

void Test() {
  MGraph *m;
  Init(m);
  DFSTraverse(m);
}

}

#endif //KAOYAN_DATA_STRUCTURE_ADJACENCY_MATRIX_H
