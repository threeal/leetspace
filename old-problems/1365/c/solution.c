#include <stdlib.h>

int* gNums;

int compare(const void* a, const void* b) {
  return gNums[*(int*)a] - gNums[*(int*)b];
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
  int* indices = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) indices[i] = i;

  gNums = nums;
  qsort(indices, numsSize, sizeof(int), compare);

  int* output = malloc(numsSize * sizeof(int));
  output[indices[0]] = 0;

  for (int i = 1; i < numsSize; ++i) {
    if (nums[indices[i]] == nums[indices[i - 1]]) {
      output[indices[i]] = output[indices[i - 1]];
    } else {
      output[indices[i]] = i;
    }
  }

  *returnSize = numsSize;
  return output;
}
