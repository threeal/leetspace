#include <stdlib.h>

int maxWidthRamp(int* nums, int numsSize) {
  int* decreasing = malloc(numsSize * sizeof(int));

  int decreasingSize = 0;
  decreasing[0] = 0;

  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] < nums[decreasing[decreasingSize]]) {
      decreasing[++decreasingSize] = i;
      if (nums[i] == 0) break;
    }
  }

  int ramp = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    while (nums[decreasing[decreasingSize]] <= nums[i]) {
      if (i - decreasing[decreasingSize] > ramp) {
        ramp = i - decreasing[decreasingSize];
      }
      --decreasingSize;
      if (decreasingSize < 0) {
        free(decreasing);
        return ramp;
      }
    }
  }

  free(decreasing);
  return ramp;
}
