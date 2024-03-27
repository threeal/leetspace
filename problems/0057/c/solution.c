#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
  (void)intervalsColSize;
  (void)newIntervalSize;

  int** newIntervals = malloc(sizeof(int*) * (intervalsSize + 1));

  *returnSize = 0;

  int i = 0;
  while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
    newIntervals[(*returnSize)++] = intervals[i];
    ++i;
  }

  while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
    if (intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
    if (intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
    ++i;
  }
  newIntervals[(*returnSize)++] = newInterval;

  while (i < intervalsSize) {
    newIntervals[(*returnSize)++] = intervals[i];
    ++i;
  }

  *returnColumnSizes = malloc(sizeof(int*) * (*returnSize));
  for (int i = 0; i <= *returnSize; ++i) {
    (*returnColumnSizes)[i] = 2;
  }

  return newIntervals;
}
