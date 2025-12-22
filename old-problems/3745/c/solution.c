#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maximizeExpressionOfThree(int* nums, int numsSize) {
  qsort(nums, 3, sizeof(int), compare);

  int c = nums[0], b = nums[1], a = nums[2];
  for (int i = 3; i < numsSize; ++i) {
    if (nums[i] > b) {
      if (nums[i] > a) {
        b = a;
        a = nums[i];
      } else {
        b = nums[i];
      }
    } else if (nums[i] < c) {
      c = nums[i];
    }
  }

  return a + b - c;
}
