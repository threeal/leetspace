#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* outputs = malloc(sizeof(int) * (*returnSize));
  int* outIt = outputs;

  int i = 0;
  while (i < numsSize && nums[i] < 0) {
    nums[i] *= nums[i];
    ++i;
  }

  int j = i - 1;
  while (i < numsSize) {
    nums[i] *= nums[i];
    while (j >= 0 && nums[j] < nums[i]) {
      *outIt = nums[j];
      ++outIt;
      --j;
    }
    *outIt = nums[i];
    ++outIt;
    ++i;
  }

  while (j >= 0) {
    *outIt = nums[j];
    ++outIt;
    --j;
  }

  return outputs;
}
