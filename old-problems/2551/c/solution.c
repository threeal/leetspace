#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

long long putMarbles(int* weights, int weightsSize, int k) {
  for (int i = 1; i < weightsSize; ++i) {
    weights[i - 1] += weights[i];
  }

  --weightsSize, --k;
  qsort(weights, weightsSize, sizeof(int), compare);

  long long min = 0;
  for (int i = 0; i < k; ++i) {
    min += weights[i];
  }

  long long max = 0;
  for (int i = weightsSize - k; i < weightsSize; ++i) {
    max += weights[i];
  }

  return max - min;
}
