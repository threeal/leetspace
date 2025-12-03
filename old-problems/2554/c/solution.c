#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
  qsort(banned, bannedSize, sizeof(int), compare);

  int i = 0, count = 0;
  for (int j = 1; j <= n && j <= maxSum; ++j) {
    if (i < bannedSize && banned[i] == j) {
      ++i;
      while (i < bannedSize && banned[i] == j) ++i;
    } else {
      maxSum -= j;
      ++count;
    }
  }

  return count;
}
