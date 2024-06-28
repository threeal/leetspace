#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

bool find132pattern(int* nums, int numsSize) {
  int* js = malloc((numsSize + 1) * sizeof(int));
  int* j = js;
  *j = INT_MAX;
  int k = INT_MIN;
  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] < k) {
      free(js);
      return true;
    }

    while (nums[i] > *j) {
      k = *j;
      --j;
    }

    ++j;
    *j = nums[i];
  }

  free(js);
  return false;
}
