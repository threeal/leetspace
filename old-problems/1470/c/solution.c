#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
  int* output = malloc(numsSize * sizeof(int));
  for (int i = 0; i < n; ++i) {
    output[i * 2] = nums[i];
    output[i * 2 + 1] = nums[n + i];
  }
  *returnSize = numsSize;
  return output;
}
