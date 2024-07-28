#include <stdlib.h>

int gk;

int compare(const void* a, const void* b) {
  return (*(int**)b)[gk] - (*(int**)a)[gk];
}

int** sortTheStudents(
    int** score, int scoreSize, int* scoreColSize, int k,
    int* returnSize, int** returnColumnSizes) {
  gk = k;

  qsort(score, scoreSize, sizeof(int*), compare);

  *returnSize = scoreSize;
  *returnColumnSizes = scoreColSize;
  return score;
}
