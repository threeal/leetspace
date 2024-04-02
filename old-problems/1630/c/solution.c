// The solution can be done simply by slicing the array, sorting it,
// and then iterating through it to check if each element has the same difference.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
  // Construct the result array, it defaults to true.
  bool* isArithmetics = malloc(sizeof(bool) * lSize);
  for (int i = 0; i < lSize; ++i) {
    isArithmetics[i] = true;
  }
  *returnSize = lSize;

  (void)rSize;

  // Initialize temporary array for slicing.
  int* slicedNums = malloc(sizeof(int) * numsSize);

  // Iterating over the given subarrays.
  for (int i = 0; i < lSize; ++i) {
    // Subarray with a size of 2 or less is always considered arithmetic.
    if (r[i] - l[i] <= 1) continue;

    // Copy the array with the given left and right range.
    const int range = r[i] - l[i] + 1;
    memcpy(slicedNums, nums + l[i], sizeof(int) * range);

    // Sort the subarray.
    qsort(slicedNums, range, sizeof(int), comp);

    // Check if the difference between each element is the same.
    const int diff = slicedNums[1] - slicedNums[0];
    for (int j = 2; j < range; ++j) {
      if (slicedNums[j] - slicedNums[j - 1] != diff) {
        isArithmetics[i] = false;
        break;
      }
    }
  }

  free(slicedNums);

  return isArithmetics;
}
