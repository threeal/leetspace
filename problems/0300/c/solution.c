#include <stdio.h>
#include <stdlib.h>

int fn(int* nums, int numsSize, int* cache, int start) {
  if (start >= numsSize) return 0;
  if (cache[start] >= 0) return cache[start];

  int maxLength = 0;
  const int num = start > 0 ? nums[start - 1] : -100000;
  for (int i = start; i < numsSize; ++i) {
    if (num >= nums[i]) continue;
    int length = 1 + fn(nums, numsSize, cache, i + 1);
    if (length > maxLength) maxLength = length;
  }
  cache[start] = maxLength;
  return maxLength;
}

int lengthOfLIS(int* nums, int numsSize) {
  int* cache = malloc(sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; ++i) {
    cache[i] = -1;
  }

  int length = fn(nums, numsSize, cache, 0);

  free(cache);

  return length;
}
