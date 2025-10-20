#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
  qsort(satisfaction, satisfactionSize, sizeof(int), compare);
  int maxSum = 0, sum = 0, diff = 0;
  for (int i = 0; i < satisfactionSize; ++i) {
    if ((diff += satisfaction[i]) < 0) break;
    if ((sum += diff) > maxSum) maxSum = sum;
  }
  return maxSum;
}
