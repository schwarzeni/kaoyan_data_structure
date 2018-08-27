//
// Created by schwarzeni on 2018/8/27.
//

#ifndef KAOYAN_DATA_STRUCTURE_ADJACENCY_LIST_H
#define KAOYAN_DATA_STRUCTURE_ADJACENCY_LIST_H

#include <iostream>
namespace adjacencyList {
#define MaxVertexNum 100
typedef int VertexType;
typedef int EdgeType;
typedef int InfoType;
typedef struct ArcNode { // 边表结点
  int adjvex;
  int InfoType;
  struct ArcNode *next;
} ArcNode;
typedef struct VNode { // 定点表结点
  VertexType data;
  ArcNode *first;
} VNode, *VNodeptr, AdjList[MaxVertexNum];
typedef struct {      // 邻接表
  AdjList vertices;
  int vexnum, arcnum;
} ALGraph;

/**
 * 2018/8/27
 * 初始化
 *        v0
 *       /  \
 *      v1   v2
 *     / \  /  \
 *    v3  v4---v5
 */
void Init(ALGraph *&G) {
  G = new ALGraph{};
  G->vexnum = 6;
  G->arcnum = 7;
  G->vertices[0].data = 0;
  G->vertices[0].first = new ArcNode{1, 1, new ArcNode{2, 1, nullptr}};
  G->vertices[1].data = 1;
  G->vertices[1].first = new ArcNode{0, 1, new ArcNode{3, 1, new ArcNode{4, 1, nullptr}}};
  G->vertices[2].data = 2;
  G->vertices[2].first = new ArcNode{0, 1, new ArcNode{4, 1, new ArcNode{5, 1, nullptr}}};
  G->vertices[3].data = 3;
  G->vertices[3].first = new ArcNode{1, 1, nullptr};
  G->vertices[4].data = 4;
  G->vertices[4].first = new ArcNode{1, 1, new ArcNode{2, 1, new ArcNode{5, 1, nullptr}}};
  G->vertices[5].data = 5;
  G->vertices[5].first = new ArcNode{2, 1, new ArcNode{4, 1, nullptr}};
}

void _visit(VNode *v) {
  std::cout << v->data << " ";
}

bool visited[MaxVertexNum];
/**
 * 广度优先
 * 2018/8/27
 */
void _bfs(ALGraph *G, int idx) {
  if (visited[idx]) return;
  auto *queue = new int[1000];
  int head = -1;
  int tail = -1;

  queue[++tail] = idx;
  visited[idx] = true;
  while (tail != head) {
    int curr = queue[++head];
    _visit(&(G->vertices[curr]));
    auto node = G->vertices[curr].first;
    while (node != nullptr && !visited[node->adjvex]) {
      queue[++tail] = node->adjvex;
      visited[node->adjvex] = true;
      node = node->next;
    }
  }
}
void BFSTraverse(ALGraph *G) {
  for (int i = 0; i < G->vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G->vexnum; i++)
    _bfs(G, i);
}

/**
 * 深度优先遍历
 * 2018/8/27
 */
void _dfs(ALGraph *G, int idx) {
  if (visited[idx]) return;
  _visit(&(G->vertices[idx]));
  visited[idx] = true;

  auto node = G->vertices[idx].first;
// TODO:注意
  while (node != nullptr) {
    _dfs(G, node->adjvex);
    node = node->next;
  }
}
void DFSTraverse(ALGraph *G) {
  for (int i = 0; i < G->vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G->vexnum; i++) {
    _dfs(G, i);
  }
}

void Test() {
  ALGraph *G;
  Init(G);
  DFSTraverse(G);
}

}

#endif //KAOYAN_DATA_STRUCTURE_ADJACENCY_LIST_H
