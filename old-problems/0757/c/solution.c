#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return aa[1] == bb[1] ? bb[0] - aa[0] : aa[1] - bb[1];
}

int intersectionSizeTwo(
    int** intervals, int intervalsSize, int* intervalsColSize) {
  (void)intervalsColSize;

  qsort(intervals, intervalsSize, sizeof(int*), compare);

  int* nums = malloc(intervalsSize * 2 * sizeof(int));
  int numsSize = 0;

  nums[numsSize++] = intervals[0][1] - 1;
  nums[numsSize++] = intervals[0][1];

  for (int i = 1; i < intervalsSize; ++i) {
    if (intervals[i][0] > nums[numsSize - 1]) {
      nums[numsSize++] = intervals[i][1] - 1;
      nums[numsSize++] = intervals[i][1];
    } else if (intervals[i][0] > nums[numsSize - 2]) {
      nums[numsSize++] = intervals[i][1];
    }
  }

  free(nums);
  return numsSize;
}
