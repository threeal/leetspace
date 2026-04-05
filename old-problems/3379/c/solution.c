#include <stdlib.h>

int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
  int* output = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    output[i] = nums[(numsSize + (i + nums[i]) % numsSize) % numsSize];
  }
  *returnSize = numsSize;
  return output;
}
