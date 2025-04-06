#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
  const int numsSize = gridSize * gridColSize[0];
  int* nums = malloc(numsSize * sizeof(int));

  const int mod = grid[0][0] % x;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] % x != mod) return -1;
      nums[i * gridColSize[i] + j] = grid[i][j];
    }
  }

  qsort(nums, numsSize, sizeof(int), compare);
  const int mid = numsSize / 2;
  const int median = nums[mid];

  int operations = 0;
  for (int i = 0; i < mid; ++i) {
    operations += (median - nums[i]) / x;
  }

  for (int i = mid + 1; i < numsSize; ++i) {
    operations += (nums[i] - median) / x;
  }

  free(nums);
  return operations;
}
