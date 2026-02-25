#include <stdlib.h>

int compare(const void* a, const void* b) {
  const int aa = *(int*)a;
  const int bb = *(int*)b;
  const int ai = __builtin_popcount(aa);
  const int bi = __builtin_popcount(bb);
  return ai == bi ? aa - bb : ai - bi;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
  qsort(arr, arrSize, sizeof(int), compare);
  *returnSize = arrSize;
  return arr;
}
