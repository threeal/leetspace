#include <stdlib.h>

int compare(const void* a, const void* b) {
  return **(int**)a - **(int**)b;
}

int** merge(
    int** intervals, int intervalsSize, int* intervalsColSize,
    int* returnSize, int** returnColumnSizes) {
  qsort(intervals, intervalsSize, sizeof(int*), compare);

  int i = 0;
  for (int j = 1; j < intervalsSize; ++j) {
    if (intervals[i][1] >= intervals[j][0]) {
      intervals[i][1] = intervals[i][1] >= intervals[j][1]
          ? intervals[i][1]
          : intervals[j][1];
    } else {
      ++i;
      intervals[i] = intervals[j];
    }
  }

  *returnSize = i + 1;
  *returnColumnSizes = intervalsColSize;
  return intervals;
}
