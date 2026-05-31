#include <stdlib.h>

int firstStableIndex(int* nums, int numsSize, int k) {
  int* mins = malloc(numsSize * sizeof(int));

  mins[numsSize - 1] = nums[numsSize - 1];
  for (int i = numsSize - 1; i > 0; --i) {
    mins[i - 1] = nums[i - 1] < mins[i] ? nums[i - 1] : mins[i];
  }

  int max = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > max) max = nums[i];
    if (max - mins[i] <= k) {
      free(mins);
      return i;
    }
  }

  free(mins);
  return -1;
}
