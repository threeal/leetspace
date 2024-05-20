#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
  qsort(happiness, happinessSize, sizeof(int), comp);

  long long sum = 0;
  for (int i = 0; i < k; ++i) {
    if (happiness[i] <= i) break;
    sum += happiness[i] - i;
  }

  return sum;
}
