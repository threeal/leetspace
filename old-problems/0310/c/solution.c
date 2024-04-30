#include <stdlib.h>
#include <string.h>

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
  (void)edgesColSize;

  if (n == 1) {
    *returnSize = 1;
    int* returnData = malloc(sizeof(int));
    *returnData = 0;
    return returnData;
  }

  int* nextsCountOf = malloc(n * sizeof(int));
  memset(nextsCountOf, 0, n * sizeof(int));
  for (int i = 0; i < edgesSize; ++i) {
    ++nextsCountOf[edges[i][0]];
    ++nextsCountOf[edges[i][1]];
  }

  int** nextsOf = malloc(n * sizeof(int*));
  for (int i = 0; i < n; ++i) {
    nextsOf[i] = malloc(nextsCountOf[i] * sizeof(int));
  }

  int* nextsCounterOf = malloc(n * sizeof(int));
  memset(nextsCounterOf, 0, n * sizeof(int));
  for (int i = 0; i < edgesSize; ++i) {
    nextsOf[edges[i][0]][nextsCounterOf[edges[i][0]]++] = edges[i][1];
    nextsOf[edges[i][1]][nextsCounterOf[edges[i][1]]++] = edges[i][0];
  }

  int* queue = malloc(n * sizeof(int));
  int queueBegin = 0;
  int queueEnd = 0;
  for (int node = 0; node < n; ++node) {
    if (nextsCountOf[node] == 1) queue[queueEnd++] = node;
  }

  while (queueEnd < n) {
    for (int i = queueEnd - queueBegin; i > 0; --i) {
      for (int j = 0; j < nextsCountOf[queue[queueBegin]]; ++j) {
        if (--nextsCounterOf[nextsOf[queue[queueBegin]][j]] == 1) {
          queue[queueEnd++] = nextsOf[queue[queueBegin]][j];
        }
      }
      ++queueBegin;
    }
  }

  *returnSize = queueEnd - queueBegin;
  int* returnData = malloc(*returnSize * sizeof(int));
  memcpy(returnData, queue + queueBegin, *returnSize * sizeof(int));

  free(queue);
  free(nextsCounterOf);
  for (int i = 0; i < n; ++i) {
    free(nextsOf[i]);
  }
  free(nextsOf);
  free(nextsCountOf);

  return returnData;
}
