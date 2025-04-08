#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int* prevOf = malloc(numsSize * sizeof(int));
  int* countOf = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    prevOf[i] = -1;
    countOf[i] = 1;
  }

  int candidate = 0;
  for (int i = 0; i < numsSize; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] % nums[j] == 0 && countOf[j] + 1 > countOf[i]) {
        prevOf[i] = j;
        countOf[i] = countOf[j] + 1;
      }
    }

    if (countOf[i] > countOf[candidate]) {
      candidate = i;
    }
  }

  int* output = malloc(countOf[candidate] * sizeof(int));
  int outputSize = 0;
  for (int i = candidate; i >= 0; i = prevOf[i]) {
    output[outputSize++] = nums[i];
  }

  free(countOf);
  free(prevOf);

  *returnSize = outputSize;
  return output;
}
