#include <stdlib.h>

int* minimumCost(
    int n, int** edges, int edgesSize, int* edgesColSize,
    int** query, int querySize, int* queryColSize, int* returnSize) {
  (void)n;
  (void)edges;
  (void)edgesSize;
  (void)edgesColSize;
  (void)query;
  (void)queryColSize;
  *returnSize = querySize;
  return malloc(querySize * sizeof(int));
}
