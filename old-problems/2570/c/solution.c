#include <stdlib.h>

int** mergeArrays(
    int** nums1, int nums1Size, int* nums1ColSize,
    int** nums2, int nums2Size, int* nums2ColSize,
    int* returnSize, int** returnColumnSizes) {
  int** output = malloc((nums1Size + nums2Size) * sizeof(int*));
  int* outputColSize = malloc((nums1Size + nums2Size) * sizeof(int));
  int outputSize = 0;

  int i1 = 0, i2 = 0;
  while (i1 < nums1Size && i2 < nums2Size) {
    if (nums1[i1][0] == nums2[i2][0]) {
      nums1[i1][1] += nums2[i2][1];
      output[outputSize] = nums1[i1];
      outputColSize[outputSize] = nums1ColSize[i1];
      ++outputSize, ++i1, ++i2;
    } else {
      if (nums1[i1][0] < nums2[i2][0]) {
        output[outputSize] = nums1[i1];
        outputColSize[outputSize] = nums1ColSize[i1];
        ++outputSize, ++i1;
      } else {
        output[outputSize] = nums2[i2];
        outputColSize[outputSize] = nums2ColSize[i2];
        ++outputSize, ++i2;
      }
    }
  }

  while (i1 < nums1Size) {
    output[outputSize] = nums1[i1];
    outputColSize[outputSize] = nums1ColSize[i1];
    ++outputSize, ++i1;
  }

  while (i2 < nums2Size) {
    output[outputSize] = nums2[i2];
    outputColSize[outputSize] = nums2ColSize[i2];
    ++outputSize, ++i2;
  }

  *returnSize = outputSize;
  *returnColumnSizes = outputColSize;
  return output;
}
