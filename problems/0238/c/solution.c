#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* res = malloc(sizeof(int) * numsSize);

  res[0] = 1;
  for (int i = 1; i < numsSize; ++i) {
    res[i] = res[i - 1] * nums[i - 1];
  }

  int temp = nums[numsSize - 1];
  for (int i = numsSize - 2; i >= 0; --i) {
    res[i] *= temp;
    temp *= nums[i];
  }

  return res;
}
