// The solution can be done simply by first sorting the array and then
// iterating from left and right to get the minimized sum of pairs.

#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minPairSum(int* nums, int numsSize) {
  // Sort the given array.
  qsort(nums, numsSize, sizeof(int), comp);

  // Declare left and right pointers.
  int* left = nums;
  int* right = nums + numsSize - 1;

  // Iterate from left and right to get the maximum sum of each pair.
  int res = 0;
  while (left < right) {
    if (*left + *right > res)
      res = *left + *right;
    ++left;
    --right;
  }

  return res;
}
