#include <stdlib.h>

int* countPoints(
    int** points, int pointsSize, int* pointsColSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  (void)pointsColSize;
  (void)queriesColSize;
  int* output = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    int count = 0;
    const int r2 = queries[i][2] * queries[i][2];
    for (int j = 0; j < pointsSize; ++j) {
      const int x = points[j][0] - queries[i][0];
      const int y = points[j][1] - queries[i][1];
      if (x * x + y * y <= r2) ++count;
    }
    output[i] = count;
  }
  *returnSize = queriesSize;
  return output;
}
