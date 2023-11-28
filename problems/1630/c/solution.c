#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void quickSort(int* low, int* high);

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
    quickSort(slicedNums, slicedNums + range - 1);

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

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void quickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j >= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  quickSort(low, i - 1);
  quickSort(i + 1, high);
}
