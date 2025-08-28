#include <stdlib.h>

int* findKDistantIndices(
    int* nums, int numsSize, int key, int k, int* returnSize) {
  int* indices = malloc(numsSize * sizeof(int));
  int indicesSize = 0;

  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == key) {
      int l = i > k ? i - k : 0;
      if (indicesSize > 0 && indices[indicesSize - 1] + 1 > l) {
        l = indices[indicesSize - 1] + 1;
      }

      const int r = i + k < numsSize ? i + k : numsSize - 1;
      while (l <= r) indices[indicesSize++] = l++;
    }
  }

  *returnSize = indicesSize;
  return indices;
}
