#include <stdbool.h>
#include <stdlib.h>

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
  bool* output = malloc(numsSize * sizeof(bool));

  int ans = 0;
  for (int i = 0; i < numsSize; ++i) {
    ans = ((ans << 1) + nums[i]) % 5;
    output[i] = ans == 0;
  }

  *returnSize = numsSize;
  return output;
}
