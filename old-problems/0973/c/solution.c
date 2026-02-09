#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return (aa[0] * aa[0] + aa[1] * aa[1]) - (bb[0] * bb[0] + bb[1] * bb[1]);
}

int** kClosest(
    int** points, int pointsSize, int* pointsColSize, int k,
    int* returnSize, int** returnColumnSizes) {
  qsort(points, pointsSize, sizeof(int*), compare);

  *returnSize = k;
  *returnColumnSizes = pointsColSize;
  return points;
}
