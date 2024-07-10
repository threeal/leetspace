#include <stdlib.h>

int longestSubarray(int* nums, int numsSize, int limit) {
  int longest = 0;

  int* increasing = malloc(numsSize * sizeof(int));
  int* increasingFront = increasing;
  int* increasingBack = increasingFront - 1;

  int* decreasing = malloc(numsSize * sizeof(int));
  int* decreasingFront = decreasing;
  int* decreasingBack = decreasingFront - 1;

  for (int left = numsSize - 1, right = left; left >= 0; --left) {
    while (increasingBack >= increasingFront && *increasingBack > nums[left]) {
      --increasingBack;
    }
    *(++increasingBack) = nums[left];

    while (decreasingBack >= decreasingFront && *decreasingBack < nums[left]) {
      --decreasingBack;
    }
    *(++decreasingBack) = nums[left];

    while (*decreasingFront - *increasingFront > limit) {
      if (nums[right] == *increasingFront) ++increasingFront;
      if (nums[right] == *decreasingFront) ++decreasingFront;
      --right;
    }

    if (right - left + 1 > longest) longest = right - left + 1;
  }

  free(increasing);
  free(decreasing);

  return longest;
}
