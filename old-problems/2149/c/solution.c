#include <stdlib.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int* output = malloc(numsSize * sizeof(int));

  int* positive = output;
  int* negative = output + 1;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] >= 0) {
      *positive = nums[i];
      positive += 2;
    } else {
      *negative = nums[i];
      negative += 2;
    }
  }

  return output;
}
