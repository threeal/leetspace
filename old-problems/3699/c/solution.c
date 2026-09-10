#include <stdlib.h>

int zigZagArrays(int n, int l, int r) {
  const int countsSize = r - l + 1;
  int* counts = malloc(countsSize * sizeof(int));
  for (int i = 0; i < countsSize; ++i) counts[i] = 1;

  for (int i = 1; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < countsSize; ++j) {
      const int prevSum = sum;
      sum = (sum + counts[j]) % 1000000007;
      counts[j] = prevSum;
    }

    if (++i >= n) break;

    sum = 0;
    for (int j = countsSize - 1; j >= 0; --j) {
      const int prevSum = sum;
      sum = (sum + counts[j]) % 1000000007;
      counts[j] = prevSum;
    }
  }

  int sum = 0;
  for (int i = 0; i < countsSize; ++i) {
    sum = (sum + counts[i]) % 1000000007;
  }

  free(counts);
  return (sum + sum) % 1000000007;
}
