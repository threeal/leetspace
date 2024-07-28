#include <stdlib.h>

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int triangleNumber(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int count = 0;
  for (int c = numsSize - 1; c >= 2; --c) {
    int a = 0;
    int b = c - 1;
    while (a < b) {
      if (nums[a] + nums[b] > nums[c]) {
        count += b - a;
        --b;
      } else {
        ++a;
      }
    }
  }

  return count;
}
