#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* eventualSafeNodes(
    int** graph, int graphSize, int* graphColSize, int* returnSize) {
  bool* isSafeNodes = malloc(graphSize * sizeof(bool));
  memset(isSafeNodes, 0, graphSize * sizeof(bool));
  for (int i = 0; i < graphSize; ++i) {
    if (graphColSize[i] == 0) isSafeNodes[i] = true;
  }

  bool haveNewSafeNode = true;
  while (haveNewSafeNode) {
    haveNewSafeNode = false;
    for (int i = 0; i < graphSize; ++i) {
      if (!isSafeNodes[i]) {
        bool allIsSafeNode = true;
        for (int j = 0; j < graphColSize[i]; ++j) {
          if (!isSafeNodes[graph[i][j]]) {
            allIsSafeNode = false;
            break;
          }
        }
        if (allIsSafeNode) {
          isSafeNodes[i] = true;
          haveNewSafeNode = true;
        }
      }
    }
  }

  int* safeNodes = malloc(graphSize * sizeof(int));
  int safeNodesSize = 0;

  for (int i = 0; i < graphSize; ++i) {
    if (isSafeNodes[i]) {
      safeNodes[safeNodesSize] = i;
      ++safeNodesSize;
    }
  }

  *returnSize = safeNodesSize;
  return safeNodes;
}
