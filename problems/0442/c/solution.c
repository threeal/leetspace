#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
  int* output = malloc(sizeof(int) * numsSize);
  *returnSize = 0;

  // Negates the numbers to track duplicates.
  for (int i = 0; i < numsSize; ++i) {
    if (nums[abs(nums[i]) - 1] > 0) {
      nums[abs(nums[i]) - 1] *= -1;
    } else {
      output[(*returnSize)++] = abs(nums[i]);
    }
  }

  return output;
}
