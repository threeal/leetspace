#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int** findDifference(
    int* nums1, int nums1Size, int* nums2, int nums2Size,
    int* returnSize, int** returnColumnSizes) {
  int** output = malloc(2 * sizeof(int*));

  *returnSize = 2;
  *returnColumnSizes = malloc(2 * sizeof(int));

  output[0] = malloc(nums1Size * sizeof(int));
  output[1] = malloc(nums2Size * sizeof(int));

  bool* exists = malloc(2001 * sizeof(bool));
  memset(exists, false, 2001 * sizeof(bool));

  for (int i = 0; i < nums2Size; ++i) {
    exists[nums2[i] + 1000] = true;
  }

  int size = 0;
  for (int i = 0; i < nums1Size; ++i) {
    if (!exists[nums1[i] + 1000]) {
      exists[nums1[i] + 1000] = true;
      output[0][size++] = nums1[i];
    }
  }
  (*returnColumnSizes)[0] = size;

  memset(exists, false, 2001 * sizeof(bool));

  for (int i = 0; i < nums1Size; ++i) {
    exists[nums1[i] + 1000] = true;
  }

  size = 0;
  for (int i = 0; i < nums2Size; ++i) {
    if (!exists[nums2[i] + 1000]) {
      exists[nums2[i] + 1000] = true;
      output[1][size++] = nums2[i];
    }
  }
  (*returnColumnSizes)[1] = size;

  return output;
}
