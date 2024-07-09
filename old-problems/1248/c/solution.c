#include <stdlib.h>

int numberOfSubarrays(int* nums, int numsSize, int k) {
  int* evens = malloc(k * sizeof(int));
  int evensIndex = k - 1;

  int right = numsSize;
  int left = right - 1;
  while (left >= 0 && evensIndex >= 0) {
    if (nums[left] % 2 != 0) {
      evens[evensIndex] = right - left;
      --evensIndex;
      right = left;
    }
    --left;
  }

  if (evensIndex >= 0) {
    free(evens);
    return 0;
  }
  evensIndex += k;

  int totalCount = 0;
  while (left >= 0) {
    if (nums[left] % 2 != 0) {
      totalCount += (right - left) * evens[evensIndex];
      evens[evensIndex] = right - left;
      if (--evensIndex < 0) evensIndex += k;
      right = left;
    }
    --left;
  }

  totalCount += (right - left) * evens[evensIndex];
  free(evens);

  return totalCount;
}
