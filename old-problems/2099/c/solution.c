#include <stdlib.h>

int* gNums;
int compareNums(const void* a, const void* b) {
  return gNums[*(int*)b] - gNums[*(int*)a];
}

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
  int* indices = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) indices[i] = i;

  gNums = nums;
  qsort(indices, numsSize, sizeof(int), compareNums);
  qsort(indices, k, sizeof(int), compare);

  for (int i = 0; i < k; ++i) {
    indices[i] = nums[indices[i]];
  }

  *returnSize = k;
  return indices;
}
