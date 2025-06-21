#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* findSmallestSetOfVertices(
    int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
  (void)edgesColSize;

  bool* exists = malloc(n * sizeof(bool));
  memset(exists, false, n * sizeof(bool));
  for (int i = 0; i < edgesSize; ++i) {
    exists[edges[i][1]] = true;
  }

  int* output = malloc(n * sizeof(int));
  int outputSize = 0;

  for (int i = 0; i < n; ++i) {
    if (!exists[i]) output[outputSize++] = i;
  }

  *returnSize = outputSize;
  return output;
}
