#include <stdlib.h>

int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
  int* output = malloc(numsSize * sizeof(int));
  *returnSize = numsSize;

  int max = (1 << maximumBit) - 1;
  int ans = 0;
  for (int i = 0; i < numsSize; ++i) {
    ans ^= nums[i];
    output[numsSize - i - 1] = max ^ ans;
  }

  return output;
}
