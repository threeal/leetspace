#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return aa[0] != bb[0] ? aa[0] - bb[0] : aa[1] - bb[1];
}

int numberOfPoints(int** nums, int numsSize, int* numsColSize) {
  (void)numsColSize;

  qsort(nums, numsSize, sizeof(int*), compare);

  int coverage = 0, min = nums[0][0], max = nums[0][1];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i][0] > max) {
      coverage += max - min + 1;
      min = nums[i][0];
      max = nums[i][1];
    } else if (nums[i][1] > max) {
      max = nums[i][1];
    }
  }

  return coverage + max - min + 1;
}
