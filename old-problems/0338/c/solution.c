#include <stdlib.h>

int* countBits(int n, int* returnSize) {
  int* counts = malloc((n + 1) * sizeof(int));
  counts[0] = 0;
  for (int i = 1, e = 1; i <= n; ++i) {
    if (i == e * 2) e = i;
    counts[i] = counts[i - e] + 1;
  }
  *returnSize = n + 1;
  return counts;
}
