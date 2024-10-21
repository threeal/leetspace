#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
  (void)intervalsColSize;

  int* starts = malloc(intervalsSize * sizeof(int));
  int* ends = malloc(intervalsSize * sizeof(int));

  for (int i = 0; i < intervalsSize; ++i) {
    starts[i] = intervals[i][0];
    ends[i] = intervals[i][1];
  }

  qsort(starts, intervalsSize, sizeof(int), compare);
  qsort(ends, intervalsSize, sizeof(int), compare);

  int group = 0;
  int* end = ends;
  for (int i = 0; i < intervalsSize; ++i) {
    if (starts[i] > *end) {
      ++end;
    } else {
      ++group;
    }
  }

  free(starts);
  free(ends);

  return group;
}
