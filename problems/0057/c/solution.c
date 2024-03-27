#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
  int** newIntervals = malloc(sizeof(int*) * intervalsSize + 1);

  (void)newInterval;
  (void)newIntervalSize;

  for (int i = 0; i < intervalsSize; ++i) {
    newIntervals[i] = intervals[i];
  }

  *returnSize = intervalsSize;
  *returnColumnSizes = intervalsColSize;

  return intervals;
}
