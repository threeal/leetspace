#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int leastInterval(char* tasks, int tasksSize, int n) {
  int counts[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < tasksSize; ++i) {
    ++counts[tasks[i] - 'A'];
  }

  qsort(counts, 26, sizeof(int), comp);

  int maxIntervals = counts[0] - 1;
  int intervals = maxIntervals * n;
  for (int i = 1; i < 26; ++i) {
    intervals -= maxIntervals < counts[i] ? maxIntervals : counts[i];
  }

  return tasksSize + (intervals > 0 ? intervals : 0);
}
