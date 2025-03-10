#include <stdlib.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
  int* temps = malloc(numsSize * sizeof(int));
  int tempsSize = 0, outputSize = 0, pivotCount = 0;

  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == pivot) {
      ++pivotCount;
    } else if (nums[i] < pivot) {
      nums[outputSize++] = nums[i];
    } else {
      temps[tempsSize++] = nums[i];
    }
  }

  while (--pivotCount >= 0) nums[outputSize++] = pivot;
  for (int i = 0; i < tempsSize; ++i) nums[outputSize++] = temps[i];

  free(temps);

  *returnSize = outputSize;
  return nums;
}
